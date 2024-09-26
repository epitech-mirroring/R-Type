// asio_client.cpp
#include <iostream>
#include <asio.hpp>
#include <chrono>  // For time measurement

using asio::ip::tcp;

int main() {
    asio::io_context io_context;
    tcp::socket socket(io_context);

    // Connect to the server
    tcp::resolver resolver(io_context);
    asio::connect(socket, resolver.resolve("127.0.0.1", "8080"));

    const std::size_t buffer_size =  1024 * 1024;  // 1 KB buffer
    char data[buffer_size];
    std::fill_n(data, buffer_size, 'A');  // Fill the buffer with 'A' characters

    std::cout << "Connected to server.\n";

    std::size_t total_bytes_sent = 0;
    std::size_t bytes_sent;

    // Define the total amount of data to send (e.g., 100 MB)
    std::size_t total_data_to_send =  100 * 1024 * 1024;  // 100 MB

    // Start measuring time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Send the data in chunks until all data is sent
    while (total_bytes_sent < total_data_to_send) {
        bytes_sent = socket.write_some(asio::buffer(data, buffer_size));
        total_bytes_sent += bytes_sent;
    }

    // Stop measuring time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Calculate transfer speed
    double total_megabytes_sent = static_cast<double>(total_bytes_sent) / (1024 * 1024); // MB
    double transfer_speed = total_megabytes_sent / elapsed_time.count(); // MB/s

    std::cout << "Total data sent: " << total_megabytes_sent << " MB\n";
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    std::cout << "Time taken: " << elapsed_time.count()*1000 << " miliseconds\n";
    std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";

    return 0;
}
