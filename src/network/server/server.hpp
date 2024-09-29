/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef R_TYPE_REBORN_SERVER_H
#define R_TYPE_REBORN_SERVER_H

#include <asio.hpp>
#include <iostream>

#include <asio.hpp>
#include <iostream>

class AsioUdpClient {
public:
    AsioUdpClient(const std::string& host, const std::string& port);

    void send(const std::string& message);
    std::string receive();

private:
    asio::io_context io_context_;
    asio::ip::udp::socket socket_;
    asio::ip::udp::endpoint endpoint_;
};

#endif //R_TYPE_REBORN_SERVER_H
