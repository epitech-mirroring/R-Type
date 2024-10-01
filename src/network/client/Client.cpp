/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Client.hpp"
#include <asio/ip/address.hpp>
#include <asio/ip/udp.hpp>

Client::Client(const std::string& host, unsigned short port)
    : _socket(_io_context), _endpoint(asio::ip::make_address(host), port) {
    _socket.open(asio::ip::udp::v4());
}

Client::~Client() {
    disconnect();
}

void Client::send(const std::vector<uint8_t>& data) {
    _socket.send_to(asio::buffer(data), _endpoint);
}

std::vector<uint8_t> Client::receive() {
    std::vector<uint8_t> buffer(1024);
    asio::ip::udp::endpoint sender_endpoint;
    size_t length = _socket.receive_from(asio::buffer(buffer), sender_endpoint);
    buffer.resize(length);
    return buffer;
}

void Client::disconnect() {
    if (_socket.is_open()) {
        _socket.close();
    }
}
