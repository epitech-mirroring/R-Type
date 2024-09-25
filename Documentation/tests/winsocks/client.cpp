// winsock_client.cpp
#include <iostream>
#include <winsock2.h>
#include <chrono>  // For time measurement

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;

    WSAStartup(MAKEWORD(2, 2), &wsaData);
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        return 1;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serverAddr.sin_port = htons(8080);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    const std::size_t buffer_size = 1024 * 1024;  // 1 MB buffer
    char data[buffer_size];
    std::fill_n(data, buffer_size, 'A');  // Fill buffer with 'A' characters

    std::cout << "Connected to server.\n";

    std::size_t total_bytes_sent = 0;
    int bytes_sent;
    std::size_t total_data_to_send = 100 * 1024 * 1024;  // 100 MB

    auto start_time = std::chrono::high_resolution_clock::now();

    while (total_bytes_sent < total_data_to_send) {
        bytes_sent = send(clientSocket, data, buffer_size, 0);
        if (bytes_sent == SOCKET_ERROR) {
            std::cerr << "Send failed.\n";
            break;
        }
        total_bytes_sent += bytes_sent;
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    double total_megabytes_sent = static_cast<double>(total_bytes_sent) / (1024 * 1024);
    double transfer_speed = total_megabytes_sent / elapsed_time.count();

    std::cout << "Total data sent: " << total_megabytes_sent << " MB\n";
    std::cout << "Time taken: " << elapsed_time.count() * 1000 << " milliseconds\n";
    std::cout << "Time taken: " << elapsed_time.count() << " seconds\n";
    std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
