/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "client/Client.hpp"
#include <iostream>
#include <thread>

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
        client.connect();
        std::cout << "Client connected to server" << std::endl;
        const std::vector message = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!' };

        while(true){
            client.add_to_send_queue(message);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Add a sleep interval

            if(client.get_size_recv_queue() > 0) {
                std::vector<char> const data = client.get_next_recv_queue();
                std::cout << "data received: " << "\n";
                for (const auto& byte : data) {
                    std::cout << byte;
                }
                std::cout << std::endl;
            }
        }

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //TODO register CppMonoBehaviours and run engine
    return 0;
}
