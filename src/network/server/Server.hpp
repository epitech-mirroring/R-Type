/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include <vector>
#include <unordered_map>

class Server {
public:
    explicit Server(unsigned short port);
    void start();
    void stop();
    void send(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint);

private:
    void receive();
    void handle_receive(const asio::error_code& error, std::size_t bytes_transferred);

    asio::io_context _io_context;
    asio::ip::udp::socket _socket;
    std::unordered_map<std::string, asio::ip::udp::endpoint> _clients;
    std::vector<uint8_t> _recv_buffer;
    asio::ip::udp::endpoint _remote_endpoint;
};

#endif // SERVER_HPP
