// bsd_server.cpp
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <chrono>

int main() {
    int server_fd, client_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        std::cerr << "Socket creation failed.\n";
        return -1;
    }

    // Bind the socket to port 8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed.\n";
        return -1;
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed.\n";
        return -1;
    }

    std::cout << "Server listening on port 8080...\n";

    // Accept a connection
    client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    if (client_socket < 0) {
        std::cerr << "Client connection failed.\n";
        return -1;
    }
    std::cout << "Client connected.\n";

    const std::size_t buffer_size = 1024 * 1024; // 1 MB buffer
    char data[buffer_size];

    std::size_t total_bytes_received = 0;
    ssize_t bytes_received;

    // Start measuring time
    auto start_time = std::chrono::high_resolution_clock::now();

    // Receive data from the client in chunks
    while ((bytes_received = recv(client_socket, data, buffer_size, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    // Stop measuring time
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    // Calculate transfer speed
    double total_megabytes_received = static_cast<double>(total_bytes_received) / (1024 * 1024);
    double transfer_speed = total_megabytes_received / elapsed_time.count(); // MB/s

    std::cout << "Total data received: " << total_megabytes_received << " MB\n";
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";

    // Close the socket
    close(client_socket);
    close(server_fd);

    return 0;
}
