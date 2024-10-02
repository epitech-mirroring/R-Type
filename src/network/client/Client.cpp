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
#include <asio/error_code.hpp>
#include <asio/ip/udp.hpp>

Network::Client::Client(std::string host, const unsigned short udp_port, unsigned short tcp_port)
    : _host(std::move(host)), _UDP_PORT(udp_port), _TCP_PORT(tcp_port), _udp_socket(_io_context), _tcp_socket(_io_context)
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
    } else {
        std::cout << "Connected to server with id " << static_cast<int>(_id) << std::endl;
    }

    // UDP connection init
    _udp_socket.open(asio::ip::udp::v4());
    _endpoint = asio::ip::udp::endpoint(asio::ip::address::from_string(_host), _UDP_PORT);
    _callback = std::move(function);
    receive();
}

void Network::Client::send(const std::vector<uint8_t> &data)
{
    _udp_socket.async_send_to(asio::buffer(data), _endpoint,
        [](const asio::error_code &error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << "Error: " << error.message() << std::endl;
            }
        });
    std::cout << "Data sent" << std::endl;
}

void Network::Client::receive() {
    _udp_socket.async_receive_from(asio::buffer(_recv_buffer), _endpoint,
        [this](const asio::error_code &error, std::size_t bytes_read)
        {
            if (!error) {
                if(_callback) {
                    _callback(_recv_buffer, _endpoint);
                }
                receive();
            } else {
                std::cerr << "Error: " << error.message() << std::endl;
            }
        });
}

void Network::Client::disconnect()
{
    _tcp_socket.close();
    _udp_socket.close();
}
