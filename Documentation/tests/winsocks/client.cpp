// winsock_client.cpp
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#pragma comment(lib, "Ws2_32.lib")

#define PORT "8080"
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    SOCKET connect_socket = INVALID_SOCKET;
    struct addrinfo *result = NULL, *ptr = NULL, hints;
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

    // Resolve the server address and port
    if (getaddrinfo("127.0.0.1", PORT, &hints, &result) != 0) {
        std::cerr << "Getaddrinfo failed\n";
        WSACleanup();
        return 1;
    }

    // Attempt to connect to an address
    for (ptr = result; ptr != NULL; ptr = ptr->ai_next) {
        connect_socket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (connect_socket == INVALID_SOCKET) {
            std::cerr << "Socket creation failed\n";
            WSACleanup();
            return 1;
        }

        // Connect to server
        if (connect(connect_socket, ptr->ai_addr, (int)ptr->ai_addrlen) == SOCKET_ERROR) {
            closesocket(connect_socket);
            connect_socket = INVALID_SOCKET;
            continue;
        }
        break;
    }

    freeaddrinfo(result);

    if (connect_socket == INVALID_SOCKET) {
        std::cerr << "Unable to connect to server\n";
        WSACleanup();
        return 1;
    }

    // Send data to server
    const char *message = "Hello from client";
    send(connect_socket, message, strlen(message), 0);
    std::cout << "Message sent\n";

    // Receive server response
    int bytes_received = recv(connect_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        std::cout << "Server response: " << buffer << std::endl;
    }

    // Cleanup
    closesocket(connect_socket);
    WSACleanup();

    return 0;
}
