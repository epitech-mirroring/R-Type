// bsd_client.cpp
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>

int main() {
    int client_socket;
    struct sockaddr_in server_address;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        std::cerr << "Socket creation failed.\n";
        return -1;
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        std::cerr << "Invalid address.\n";
        return -1;
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        std::cerr << "Connection failed.\n";
        return -1;
    }

    const std::size_t buffer_size = 1024 * 1024;  // 1 MB buffer
    char data[buffer_size] = { 'A' };  // Example data to send

    std::size_t total_bytes_sent = 0;
    ssize_t bytes_sent;

    // Define the total amount of data to send (e.g., 100 MB)
    std::size_t total_data_to_send = 100 * 1024 * 1024;  // 100 MB

    // Start measuring time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Send the data in chunks
    while (total_bytes_sent < total_data_to_send) {
        bytes_sent = send(client_socket, data, buffer_size, 0);
        if (bytes_sent <= 0) {
            std::cerr << "Failed to send data.\n";
            break;
        }
        total_bytes_sent += bytes_sent;
    }

    // Stop measuring time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Calculate transfer speed
    double total_megabytes_sent = static_cast<double>(total_bytes_sent) / (1024 * 1024);
    double transfer_speed = total_megabytes_sent / elapsed_time.count(); // MB/s

    std::cout << "Total data sent: " << total_megabytes_sent << " MB\n";
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    std::cout << "Time taken: " << elapsed_time.count()*1000 << " miliseconds\n";
    std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";

    // Close the socket
    close(client_socket);

    return 0;
}
