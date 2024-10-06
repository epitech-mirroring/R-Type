/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server/Server.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <TCP_port> <UDP_port>" << std::endl;
        return 1;
    }

    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[1]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[2]));

    try {
        Network::Server server(TCP_port, UDP_port);
        server.start([](const std::vector<uint8_t>& data, const asio::ip::udp::endpoint& client_endpoint) {
            // Handle received data
            std::cout << "Received data from client: " << client_endpoint << std::endl;
        });

        std::cout << "Server started on TCP port " << TCP_port << " and UDP port " << UDP_port << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception server 1: " << e.what() << std::endl;
    }

    return 0;
}
