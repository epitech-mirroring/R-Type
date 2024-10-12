/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Client.hpp"
#include <iostream>
#include <utility>
#include <asio/ip/udp.hpp>
#include <thread>

//-------------------------------------Initiator------------------------------------------
Network::Client::Client(std::string host, const unsigned short udp_port, unsigned short tcp_port)
        : _host(std::move(host)), _UDP_PORT(udp_port), _TCP_PORT(tcp_port), _udp_socket(_io_context), _tcp_socket(_io_context), _is_alive(true)
{
    _id = -1;
    _send_timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(15));
    _recv_buffer.resize(2048);
}



void Network::Client::connect()
{

    // TCP connection init
    asio::ip::tcp::resolver resolver(_io_context);
    asio::ip::tcp::resolver::results_type const endpoints = resolver.resolve(_host, std::to_string(_TCP_PORT));
    asio::error_code error;
    _tcp_endpoint = asio::connect(_tcp_socket, endpoints, error);
    if (error) {
        std::cerr << "Error: " << error.message() << std::endl;
        return;
    }
    asio::read(_tcp_socket, asio::buffer(&_id, sizeof(_id)), error);
    if (error) {
        std::cerr << "Error: " << error.message() << std::endl;
        return;
    }
    std::cout << "Get a new ID: " << static_cast<int>(_id) << std::endl;

    // UDP connection init
    _udp_socket.open(asio::ip::udp::v4());
    _endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_host), _UDP_PORT);
    _udp_socket.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
    _udp_socket.connect(_endpoint);
    _udp_socket.send(asio::buffer("Hello", 5));
    std::cout << "Connected in UDP, port " << _UDP_PORT << std::endl;

    asio::write(_tcp_socket, asio::buffer("Hello\n", 6));
    receive_udp_data();
    receive_tcp_data();

    send_udp_data_loop();

    // Run the io_context in a separate thread to keep the client open
    _io_thread = std::thread([this]() {
        while (_is_alive) {
            _io_context.run();
            _io_context.restart();
        }
    });
}

//---------------------------------------UDP methods---------------------------------------


void Network::Client::send_udp_data_loop() {
    _send_data_handler = [this](const asio::error_code& error) mutable {
        if (!error) {
            if (!_send_queue.empty()) {
                send_udp_data(_send_queue.front());
                _send_queue.pop();
            }
            _send_timer->expires_after(std::chrono::milliseconds(15));
            _send_timer->async_wait(_send_data_handler);
        }
    };
    _send_timer->async_wait(_send_data_handler);
}

void Network::Client::send_udp_data(const std::vector<char> &data)
{
    _udp_socket.async_send_to(asio::buffer(data), _endpoint,
      [this](const asio::error_code &error, std::size_t bytes_transferred) {
          if (error) {
              std::cerr << "Error: " << error.message() << std::endl;
          }
      });
}

void Network::Client::receive_udp_data() {
    _udp_socket.async_receive_from(asio::buffer(_recv_buffer), _endpoint,
       [this](const asio::error_code &error, std::size_t bytes_read)
       {
           if (!error) {
               _recv_queue.emplace(_recv_buffer.begin(), _recv_buffer.begin() + bytes_read);
               receive_udp_data();
           } else {
               std::cerr << "Error: " << error.message() << std::endl;
           }
       });
}


//---------------------------------------TCP methods---------------------------------------
void Network::Client::receive_tcp_data()
{
    asio::async_read_until(_tcp_socket, asio::dynamic_buffer(_recv_buffer), '\n',
       [this](const asio::error_code &error, std::size_t bytes_transferred)
       {
           if (!error) {
               std::string message = std::string(_recv_buffer.begin(), _recv_buffer.begin() + bytes_transferred - 1);
               if (message == "exit\n") {
                   _is_alive = false;
                   stop();
               } else {
                   receive_tcp_data();
               }
           } else {
               std::cerr << "Server disconnected" << std::endl;
               stop();
           }
       });
}

void Network::Client::send_tcp_data(const std::string& data)
{
    asio::write(_tcp_socket, asio::buffer(data + '\n'));
}

//---------------------------------------Queue methods---------------------------------------

void Network::Client::add_to_send_queue(const std::vector<char> &data)
{
    _send_queue.push(data);
}

std::vector<char> Network::Client::get_next_recv_queue()
{
    if (!_recv_queue.empty()) {
        auto data = _recv_queue.front();
        _recv_queue.pop();
        return data;
    }
    return {};
}

std::uint8_t Network::Client::get_size_recv_queue()
{
    return _recv_queue.size();
}


//---------------------------------------Stop method---------------------------------------

void Network::Client::stop()
{
    asio::write(_tcp_socket, asio::buffer("exit\n", sizeof(_id)));
    _tcp_socket.close();
    _udp_socket.close();
    _io_context.stop();
    _is_alive = false;
}

Network::Client::~Client()
{
    _io_context.stop();
    if (_io_thread.joinable()) {
        _io_thread.join();
    }
}
