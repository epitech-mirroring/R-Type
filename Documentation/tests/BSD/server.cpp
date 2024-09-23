// bsd_server.cpp - Server to measure latency and throughput
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <chrono>
#include <cstring>

#define PORT 8080
#define BUFFER_SIZE 1024
//#define BUFFER_SIZE 1024 * 1024 // 1 MB
//#define BUFFER_SIZE 10 * (1024 * 1024) // 10 MB

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *buffer = (char *)malloc(BUFFER_SIZE);


    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept the connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Measure latency and throughput
    while (true) {
        auto start = std::chrono::high_resolution_clock::now();

        // Read data from the client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if (valread <= 0) break;

        // Send response to the client
        send(new_socket, buffer, valread, 0);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        // Output the round-trip time (latency)
        std::cout << "Latency (RTT): " << elapsed.count() * 1000 << " ms" << std::endl;
    }

    close(new_socket);
    close(server_fd);
    free(buffer);
    return 0;
}
