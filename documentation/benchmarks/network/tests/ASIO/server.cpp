// asio_server.cpp
#include <iostream>
#include <asio.hpp>
#include <chrono>  // For time measurement

using asio::ip::tcp;

int main() {
    try {
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8080));

        std::cout << "Server listening on port 8080...\n";
        tcp::socket socket(io_context);

        // Wait for a connection from the client
        acceptor.accept(socket);
        std::cout << "Client connected.\n";

        const std::size_t buffer_size = 1024; // 1 MB buffer
        char data[buffer_size];

        std::size_t total_bytes_received = 0;
        std::size_t bytes_received;

        // Start measuring time
        auto start_time = std::chrono::high_resolution_clock::now();

        // Receive data from the client in chunks until all data is received
        do {
            asio::error_code error;
            bytes_received = socket.read_some(asio::buffer(data, buffer_size), error);
            if (error == asio::error::eof) {
                break; // Connection closed cleanly by peer.
            } else if (error) {
                throw asio::system_error(error); // Some other error.
            }
            total_bytes_received += bytes_received;
        } while (bytes_received > 0);

        // Stop measuring time
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed_time = end_time - start_time;

        // Calculate transfer speed
        double total_megabytes_received = static_cast<double>(total_bytes_received) / (1024 * 1024);
        double transfer_speed = total_megabytes_received / elapsed_time.count(); // MB/s

        std::cout << "Total data received: " << total_megabytes_received << " MB\n";
        std::cout << "Time taken: " << elapsed_time.count()*1000 << " miliseconds\n";
        std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
        std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
