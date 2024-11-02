/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main(const int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: ./r-type_server <TCP_port> <UDP_port>" << '\n';
        return 1;
    }

    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[1]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[2]));

    try {
        RType::Server server(TCP_port, UDP_port);
        server.runServer();


    } catch (std::exception& e) {
        std::cerr << "Exception server 1: " << e.what() << '\n';
    }

    return 0;
}
