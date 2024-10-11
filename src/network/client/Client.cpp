#include "Client.hpp"
#include <iostream>
#include <utility>
#include <asio/ip/udp.hpp>

Network::Client::Client(std::string host, const unsigned short udp_port, unsigned short tcp_port)
        : _host(std::move(host)), _UDP_PORT(udp_port), _TCP_PORT(tcp_port), _udp_socket(_io_context), _tcp_socket(_io_context), _is_alive(true)
{
    _id = -1;
}

Network::Client::~Client()
{
    _io_context.stop();
}

void Network::Client::connect(callback function)
{
    // TCP connection init
    asio::ip::tcp::resolver resolver(_io_context);
    asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(_host, std::to_string(_TCP_PORT));

    asio::error_code error;
    asio::connect(_tcp_socket, endpoints, error);
    if (error) {
        std::cerr << "Error: " << error.message() << std::endl;
        return;
    }

    asio::read(_tcp_socket, asio::buffer(&_id, sizeof(_id)), error);
    if (error) {
        std::cerr << "Error: " << error.message() << std::endl;
        return;
    }

    asio::write(_tcp_socket, asio::buffer("Hello\n", 6));

    std::cout << "Connected to server with id " << static_cast<int>(_id) << std::endl;

    receive_tcp_data();

    // UDP connection init
    std::cout << "Connecting to server with UDP on port " << _UDP_PORT << std::endl;
    _udp_socket.open(asio::ip::udp::v4());
    _endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_host), _UDP_PORT);
    _callback = std::move(function);
    receive_data();
    std::cout << "Connected to server with UDP on port " << _UDP_PORT << std::endl;
}

void Network::Client::send_data(const std::vector<uint8_t> &data)
{
    _udp_socket.async_send_to(asio::buffer(data), _endpoint,
      [this](const asio::error_code &error, std::size_t bytes_transferred) {
          if (error) {
              std::cerr << "Error udp sent : " << error.message() << std::endl;
          } else {
              std::cout << "Data sent: " << bytes_transferred << " bytes" << std::endl;
          }
      });
}

void Network::Client::receive_data() {
    _udp_socket.async_receive_from(asio::buffer(_recv_buffer), _endpoint,
       [this](const asio::error_code &error, const std::size_t bytes_read)
       {
           if (!error && bytes_read > 0)
           {
               try
               {
                   const std::string message(_recv_buffer.begin(), _recv_buffer.begin() + bytes_read);
                   std::cout << message << std::endl;

               }
               catch (const std::exception &e)
               {
                   std::cerr << e.what() << std::endl;
               }
           }
       });
}

void Network::Client::stop()
{
    asio::write(_tcp_socket, asio::buffer("bye\n", sizeof(_id)));
    _tcp_socket.close();
    _udp_socket.close();
    _io_context.stop();
}

void Network::Client::receive_tcp_data()
{
    asio::async_read_until(_tcp_socket, asio::dynamic_buffer(_recv_buffer), '\n',
       [this](const asio::error_code &error, std::size_t bytes_transferred)
       {
           if (!error) {
               std::string message = std::string(_recv_buffer.begin(), _recv_buffer.begin() + bytes_transferred - 1);
               std::cout << "Received TCP data: " << message << std::endl;
               if (message == "bye\n") {
                   _is_alive = false;
                   stop();
               } else {
                   receive_tcp_data();
               }
           } else {
               std::cerr << "read-tcp: " << error.message() << std::endl;
           }
       });
}

void Network::Client::send_tcp_data(const std::string& data)
{
    std::cout << "Sending TCP data: " << data << std::endl;
    asio::write(_tcp_socket, asio::buffer(data + '\n'));
}