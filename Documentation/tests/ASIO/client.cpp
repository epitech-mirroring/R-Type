// asio_client.cpp - ASIO Client using standalone ASIO
#include <asio.hpp>
#include <iostream>
#include <chrono>

using asio::ip::tcp;

#define BUFFER_SIZE 1024*1024

int main() {
    try {
        asio::io_context io_context;

        tcp::resolver resolver(io_context);
        tcp::resolver::results_type endpoints = resolver.resolve("127.0.0.1", "8080");

        tcp::socket socket(io_context);
        asio::connect(socket, endpoints);

        char *message = (char *)malloc(BUFFER_SIZE);
        memset(message, 'a', BUFFER_SIZE-10);
        char buffer[BUFFER_SIZE];

        int message_count = 1000;  // Number of messages to send for throughput/latency
        double total_time = 0.0;

        for (int i = 0; i < message_count; ++i) {
            auto start = std::chrono::high_resolution_clock::now();

            // Send message to server
            asio::write(socket, asio::buffer(message, strlen(message)));

            // Receive response from server
            size_t len = socket.read_some(asio::buffer(buffer));

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            total_time += elapsed.count();
        }

        // Output the average latency and throughput
        std::cout << "Average Latency (RTT): " << (total_time / message_count) * 1000 << " ms" << std::endl;

    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
