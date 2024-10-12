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

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <TCP_port> <UDP_port>" << std::endl;
        return 1;
    }

    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[1]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[2]));

    try {
        Server server(TCP_port, UDP_port);
        server.runServer();


    } catch (std::exception& e) {
        std::cerr << "Exception server 1: " << e.what() << std::endl;
    }

    return 0;
}
