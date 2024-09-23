// winsock_client.cpp
#include <winsock2.h>
#include <iostream>
#include <chrono>  // For time measurement

#pragma comment(lib, "Ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    sockaddr_in serverAddr;
    char buffer[1024] = "Test message from client";
    char recvBuffer[1024] = {0};
    int messageCount = 1000;  // Number of messages to send for testing
    double totalTime = 0.0;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock.\n";
        return 1;
    }

    // Create a socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket.\n";
        WSACleanup();
        return 1;
    }

    // Set up server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Connect to localhost

    // Connect to the server
    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to the server.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to server.\n";

    // Send multiple messages and measure round-trip time (RTT)
    for (int i = 0; i < messageCount; ++i) {
        // Record the start time
        auto start = std::chrono::high_resolution_clock::now();

        // Send the message to the server
        send(clientSocket, buffer, strlen(buffer), 0);

        // Receive the echoed message from the server
        int bytesReceived = recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);

        // Record the end time
        auto end = std::chrono::high_resolution_clock::now();

        // Calculate the round-trip time (RTT)
        std::chrono::duration<double> elapsed = end - start;
        totalTime += elapsed.count();

        std::cout << "Message " << i + 1 << " RTT: " << elapsed.count() * 1000 << " ms\n";
    }

    // Print the average RTT
    std::cout << "Average RTT for " << messageCount << " messages: " << (totalTime / messageCount) * 1000 << " ms\n";

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
