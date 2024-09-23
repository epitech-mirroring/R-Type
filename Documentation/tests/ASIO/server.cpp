// asio_server.cpp - ASIO Server using standalone ASIO
#include <asio.hpp>
#include <iostream>
#include <chrono>

using asio::ip::tcp;

#define BUFFER_SIZE 1024 * 1024

int main() {
    try {
        asio::io_context io_context;

        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));
        std::cout << "Server is listening on port 8080...\n";

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            char buffer[BUFFER_SIZE] = {0};

            while (true) {
                auto start = std::chrono::high_resolution_clock::now();

                // Receive data from client
                size_t len = socket.read_some(asio::buffer(buffer));

                // Send response to client
                asio::write(socket, asio::buffer(buffer, len));

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> elapsed = end - start;

                // Log latency (round-trip time)
                std::cout << "Latency (RTT): " << elapsed.count() * 1000 << " ms" << std::endl;
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
