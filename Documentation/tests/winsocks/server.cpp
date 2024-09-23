// winsock_server.cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

#define PORT "8080"
#define BUFFER_SIZE 1024
//#define BUFFER_SIZE 1024 * 1024 // 1 MB
//#define FILE_SIZE 100 * (1024 * 1024) // 100 MB

int main() {
    WSADATA wsaData;
    SOCKET server_socket, client_socket;
    struct addrinfo *result = NULL, hints;
    char buffer[BUFFER_SIZE] = {0};

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed\n";
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the local address and port
    if (getaddrinfo(NULL, PORT, &hints, &result) != 0) {
        std::cerr << "Getaddrinfo failed\n";
        WSACleanup();
        return 1;
    }

    // Create a socket
    server_socket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed\n";
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Bind the socket
    if (bind(server_socket, result->ai_addr, (int)result->ai_addrlen) == SOCKET_ERROR) {
        std::cerr << "Bind failed\n";
        freeaddrinfo(result);
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    // Listen for incoming connections
    if (listen(server_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed\n";
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for a connection...\n";

    // Accept a client socket
    client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == INVALID_SOCKET) {
        std::cerr << "Accept failed\n";
        closesocket(server_socket);
        WSACleanup();
        return 1;
    }

    // Receive data from client
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        std::cout << "Received: " << buffer << std::endl;
        send(client_socket, "Message received", 16, 0);
        std::cout << "Response sent\n";
    }

    // Cleanup
    closesocket(client_socket);
    closesocket(server_socket);
    WSACleanup();

    return 0;
}
