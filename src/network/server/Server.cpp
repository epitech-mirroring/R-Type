/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"

#include <cstdint>
#include <iostream>
#include <asio/error_code.hpp>
#include <asio/ip/udp.hpp>

Server::Server(unsigned short port)
    : _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), port)), _recv_buffer(1024) {}

void Server::start() {
    receive();
    _io_context.run();
}

void Server::stop() {
    _io_context.stop();
    if (_socket.is_open()) {
        _socket.close();
    }
}

void Server::send(const std::vector<uint8_t>& data, const asio::ip::udp::endpoint& client_endpoint) {
    _socket.send_to(asio::buffer(data), client_endpoint);
}

void Server::receive() {
    _socket.async_receive_from(
        asio::buffer(_recv_buffer), _remote_endpoint,
        [this](const asio::error_code& error, std::size_t bytes_transferred) {
            handle_receive(error, bytes_transferred);
        });
}

void Server::handle_receive(const asio::error_code& error, std::size_t bytes_transferred) {
    if (!error && bytes_transferred > 0) {
        std::string client_key = _remote_endpoint.address().to_string() + ":" + std::to_string(_remote_endpoint.port());
        _clients[client_key] = _remote_endpoint;

        // Process received data (for example, echo it back to the client)
        const std::vector data(_recv_buffer.begin(), _recv_buffer.begin() + bytes_transferred);
        send(data, _remote_endpoint);
    }
    receive();
}
