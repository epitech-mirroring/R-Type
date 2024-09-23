// bsd_client.cpp - Client to measure latency and throughput
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <cstring>

#define PORT 8080
#define BUFFER_SIZE 1024
//#define BUFFER_SIZE 1024 * 1024 // 1 MB
//#define BUFFER_SIZE 10 * (1024 * 1024) // 10 MB

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    // make a message of the size of the buffer
    char *message = (char *)malloc(BUFFER_SIZE);
    memset(message, 'a', BUFFER_SIZE-10);

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cerr << "Socket creation error\n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported\n";
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr << "Connection failed\n";
        return -1;
    }

    // Measure throughput and latency over multiple iterations
    int message_count = 10;
    double total_time = 0.0;

    for (int i = 0; i < message_count; ++i) {
        auto start = std::chrono::high_resolution_clock::now();

        // Send message to server
        send(sock, message, strlen(message), 0);

        // Read server response
        int valread = read(sock, buffer, BUFFER_SIZE);
        if (valread <= 0) break;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        total_time += elapsed.count();
    }

    // Output the average latency and throughput
    std::cout << "Average Latency (RTT): " << (total_time / message_count) * 1000 << " ms" << std::endl;

    close(sock);
    return 0;
}
