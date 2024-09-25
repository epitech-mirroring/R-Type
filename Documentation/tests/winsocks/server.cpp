// winsock_server.cpp
#include <iostream>
#include <winsock2.h>
#include <chrono>  // For time measurement
#include <cstring> // For memset

#pragma comment(lib, "ws2_32.lib") // Link the Winsock library

int main() {
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    sockaddr_in serverAddr, clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    // Create the server socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed. Error: " << WSAGetLastError() << "\n";
        WSACleanup();
        return 1;
    }

    // Setup the server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8080);

    // Bind the server socket
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    // Listen for incoming connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server listening on port 8080...\n";

    // Accept a connection from a client
    clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Accept failed. Error: " << WSAGetLastError() << "\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Client connected.\n";

    const std::size_t buffer_size = 1024 * 1024;  // 1 MB buffer
    char data[buffer_size];
    int bytes_received;
    std::size_t total_bytes_received = 0;

    // Start time measurement
    auto start_time = std::chrono::high_resolution_clock::now();

    // Receive data in chunks
    while (true) {
        bytes_received = recv(clientSocket, data, buffer_size, 0);
        if (bytes_received <= 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    // End time measurement
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_time = end_time - start_time;

    double total_megabytes_received = static_cast<double>(total_bytes_received) / (1024 * 1024);
    double transfer_speed = total_megabytes_received / elapsed_time.count();  // MB/s

    std::cout << "Total data received: " << total_megabytes_received << " MB\n";
    std::cout << "Time taken: " << elapsed_time.count() * 1000 << " milliseconds\n";
    std::cout << "Transfer speed: " << transfer_speed << " MB/s\n";

    // Cleanup
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
