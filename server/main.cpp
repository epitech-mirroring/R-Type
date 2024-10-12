/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "server/Server.hpp"
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
        Network::Server server(TCP_port, UDP_port);

        // Create a thread for the network operations
        std::thread network_thread([&server]() {
            server.start();
        });

        // Run the rest of the application in the main thread
        std::cout << "Server started on TCP port " << TCP_port << " and UDP port " << UDP_port << std::endl;

        while(true){
            std::vector<uint8_t> const connected_clients = server.get_connected_clients();
            for (const auto& client : connected_clients) {
                std::cout << "Client id: " << static_cast<int>(client) << std::endl;
                server.add_to_udp_send_queue(std::vector{'H', 'e', 'l', 'l', 'o'}, client);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Add a sleep interval
            if(server.get_size_recv_queue() > 0){
                std::unordered_map<int8_t, std::vector<char>> data = server.get_next_recv_queue();
                std::cout << "Data received: from client id: " << static_cast<int>(data.begin()->first) << "\n";
                for (const auto& byte : data[0]) {
                    std::cout << byte;
                }
                std::cout << std::endl;
            }
        }

        //std::this_thread::sleep_for(std::chrono::seconds(5));
        //server.send_data(std::vector<uint8_t>{'H', 'e', 'l', 'l', 'o'}, 0);
        //std::this_thread::sleep_for(std::chrono::seconds(3));
        //server.stop();

        // Join the network thread before exiting
        network_thread.join();

    } catch (std::exception& e) {
        std::cerr << "Exception server 1: " << e.what() << std::endl;
    }

    return 0;
}
