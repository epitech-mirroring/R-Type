/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "client/Client.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <host> <UDP port> <TCP port>" << std::endl;
        return 1;
    }

    const std::string host = argv[1];
    const unsigned short TCP_port = static_cast<unsigned short>(std::stoi(argv[2]));
    const unsigned short UDP_port = static_cast<unsigned short>(std::stoi(argv[3]));

    try {
        Network::Client client(host, UDP_port, TCP_port);
        std::cout << "Client trying to connect to server..." << std::endl;
        client.connect([](const std::vector<uint8_t>& data, const asio::ip::udp::endpoint& client_endpoint) {
            // Handle received data
            std::cout << "Received data from server" << std::endl;
        });

        const std::vector<uint8_t> message = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!' };
        client.send_data(message);
        client.send_data(message);
        client.send_data(message);
        sleep(1);
        client.send_tcp_data("Hello test de la communication en TCP");

        std::cout << "Message sent!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
