/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <asio.hpp>
#include <vector>

class Client {
public:
    Client(const std::string& host, unsigned short port);
    ~Client();

    bool isConnected();
    void send(const std::vector<uint8_t>& data);
    std::vector<uint8_t> receive();
    void disconnect();

private:
    asio::io_context _io_context;
    asio::ip::udp::socket _socket;
    asio::ip::udp::endpoint _endpoint;
};

#endif // CLIENT_HPP
