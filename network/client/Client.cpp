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
#include <asio/ip/tcp.hpp>
#include "NetworkException.hpp"
#include <thread>

//-------------------------------------Initiator------------------------------------------
Network::Client::Client(std::string host, const unsigned short udp_port, unsigned short tcp_port)
        : _host(std::move(host)), _TCP_PORT(tcp_port), _UDP_PORT(udp_port), _udp_socket(_io_context), _tcp_socket(_io_context), _id(-1), _is_alive(true)
{
    _send_timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(1));
}



void Network::Client::connect()
{
    // TCP connection init
    asio::ip::tcp::resolver resolver(_io_context);
    asio::ip::tcp::resolver::results_type const endpoints = resolver.resolve(_host, std::to_string(_TCP_PORT));
    asio::error_code error;
    _tcp_endpoint = asio::connect(_tcp_socket, endpoints, error);
    if (error) {
        throw NetworkException("Error: " + error.message());
    }
    asio::read(_tcp_socket, asio::buffer(&_id, sizeof(_id)), error);
    if (error) {
        throw NetworkException("Error: " + error.message());
    }
    std::cout << "Got a new ID: " << _id << '\n';

    // UDP connection init
    _udp_socket.open(asio::ip::udp::v4());
    _endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_host), _UDP_PORT);
    _udp_socket.bind(asio::ip::udp::endpoint(asio::ip::udp::v4(), 0));
    _udp_socket.connect(_endpoint);

    // Write through the TCP the client endpoint
    asio::write(_tcp_socket, asio::buffer(&_udp_socket.local_endpoint(), sizeof(asio::ip::udp::endpoint)));

    std::cout << "Connected in UDP, port " << _UDP_PORT << '\n';

    receive_udp_data();
    receive_tcp_data();

    //send_udp_data_loop(); //Todo fix me

    // Run the io_context in a separate thread to keep the client open
    _io_thread = std::thread([this]() {
        _io_context.run();
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
            _send_timer->expires_after(std::chrono::milliseconds(1));
            _send_timer->async_wait(_send_data_handler);
        }
    };
    _send_timer->async_wait(_send_data_handler);
}

void Network::Client::send_udp_data(const std::vector<char> &data)
{
    _udp_socket.async_send_to(asio::buffer(data), _endpoint,
      [this](const asio::error_code &error, std::size_t  /*bytes_transferred*/) {
          if (error) {
              std::cerr << "Error: " << error.message() << '\n';
          }
      });
}

void Network::Client::receive_udp_data() {
    _udp_socket.async_receive_from(_recv_udp_buffer.prepare(512), _endpoint,
       [this](const asio::error_code &error, const std::size_t bytes_read)
       {
           if (!error) {
               _recv_udp_buffer.commit(bytes_read);
               std::istream ist(&_recv_udp_buffer);
               std::vector<char> data((std::istreambuf_iterator<char>(ist)), std::istreambuf_iterator<char>());
               _recv_queue.emplace(std::move(data));
               receive_udp_data();
           } else {
               std::cerr << "Error: " << error.message() << '\n';
           }
       });
}

//---------------------------------------TCP methods---------------------------------------
void Network::Client::receive_tcp_data()
{
    asio::async_read_until(_tcp_socket, _recv_tcp_buffer, '\n',
       [this](const asio::error_code &error, std::size_t  /*bytes_transferred*/)
       {
           if (!error) {
               std::istream ist(&_recv_tcp_buffer);
               std::string message;
               std::getline(ist, message);
               if (message == "exit") {
                   _is_alive = false;
                   stop();
               } else {
                   receive_tcp_data();
               }
           } else {
               std::cerr << "Server disconnected" << '\n';
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

size_t Network::Client::get_size_recv_queue()
{
    return _recv_queue.size();
}

bool Network::Client::is_alive() const
{
    return _is_alive;
}

//---------------------------------------Stop method---------------------------------------

void Network::Client::stop()
{
    _is_alive = false;
}

Network::Client::~Client()
{
    _io_context.stop();

    if (_io_thread.joinable()) {
        _io_thread.join();
    }
    exit(0); //todo: remove this
}

//---------------------------------------Getters---------------------------------------

int Network::Client::getId() const
{
    return _id;
}
