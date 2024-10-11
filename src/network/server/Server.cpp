/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include <cstdint>
#include <iostream>
#include <asio.hpp>

Network::Server::Server(unsigned short TCP_port, unsigned short UDP_port)
    :_io_context(), _acceptor(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), TCP_port)),
      _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), UDP_port)) {
    _TCP_port = TCP_port;
    _UDP_port = UDP_port;
    _recv_buffer.resize(1024);
}

void Network::Server::start(callback function) {
    _callback = std::move(function);

    std::cout << "Server started on TCP port " << _TCP_port << " and UDP port " << _UDP_port << std::endl;
    std::cout << "Server hostname: " << asio::ip::host_name() << std::endl;
    connect_new_client();
    receive_data();
    const auto serverStartedMessage = std::make_shared<ServerStarted>("Server has started successfully");
    _internal_queue.push(serverStartedMessage);
    _io_context.run(); // run the io_context event loop for asyncronous operations (non-blocking)
}

void Network::Server::stop() {
    _io_context.stop(); // stop the io_context event loop to stop asyncronous operations
    for (int i = 0; i < _clients.size(); i++) {
        if (_tcp_sockets[i]->is_open()) {
            _tcp_sockets[i]->close();
        }
    }
    if (_socket.is_open()) {
        _socket.close();
    }
}

void Network::Server::send_data(const std::vector<uint8_t>& data, const asio::ip::udp::endpoint& client_endpoint) {
    _socket.async_send_to(asio::buffer(data), client_endpoint,
        [](const asio::error_code& error, std::size_t bytes_transferred) {
            if (error) {
                std::cerr << "Error (send udp): " << error.message() << std::endl;
            }
        }
    );
}

void Network::Server::send_data(const std::vector<uint8_t>& data, uint8_t id)
{
    if (_clients.find(id) != _clients.end()) {
        _socket.async_send_to(asio::buffer(data), _clients[id],
            [](const asio::error_code& error, std::size_t bytes_transferred) {
                if (error) {
                    std::cerr << "Error (send udp): " << error.message() << std::endl;
                }
            }
        );
    }
}

void Network::Server::send_data() {
    if (!_send_queue.empty()) {
        if (auto data = _send_queue.front(); _clients.contains(data.begin()->first)) {
            _socket.async_send_to(asio::buffer(data.begin()->second), _clients[data.begin()->first],
                [this](const asio::error_code& error, std ::size_t bytes_transferred) {
                    if (error) {
                        std::cerr << "Error (send udp): " << error.message() << std::endl;
                    }
                }
            );
        }
        _send_queue.pop();
    }
}

void Network::Server::connect_new_client() {
    auto socket = std::make_shared<asio::ip::tcp::socket>(_io_context);

    // Accept new client connection in TCP
    _acceptor.async_accept(*socket, [this, socket](const asio::error_code& error) {
        if (!error) {
            int8_t id = 0; // create_client_id();
            while (_clients.contains(id)) {
                id++; // id = create_client_id();
            }
            _tcp_sockets[id] = socket;
            auto clientConnectedMessage = std::make_shared<ClientConnected>("Client connected with id: " + std::to_string(id), id);
            std::cout << "Client connected with id: " << static_cast<int>(id) << std::endl;
            std::cout << "Client IP: " << socket->remote_endpoint().address().to_string() << std::endl;
            std::cout << "Client port: " << socket->remote_endpoint().port() << std::endl;

            // Wait for UDP connection from the same client
            asio::write(*_tcp_sockets[id], asio::buffer(&id, sizeof(id)));

            _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint, [this, id](const asio::error_code& error, std::size_t bytes_transferred) {
                if (!error) {
                    _clients[id] = _remote_endpoint;
                    std::cout << "Client UDP connected with id: " << static_cast<int>(id) << std::endl;
                    std::cout << "Client UDP IP: " << _remote_endpoint.address().to_string() << std::endl;
                    std::cout << "Client UDP port: " << _remote_endpoint.port() << std::endl;
                }
            });
            receive_tcp_data(socket, id);
            connect_new_client();
        }
    });
}

void Network::Server::receive_tcp_data(const std::shared_ptr<asio::ip::tcp::socket>& tcp_socket, int8_t id)
{
    auto buffer = std::make_shared<std::vector<uint8_t>>(1024); // Adjust the buffer size as needed

    tcp_socket->async_read_some(asio::buffer(*buffer),
        [this, tcp_socket, buffer, id](const asio::error_code& error, std::size_t bytes_transferred) {
            if (!error && bytes_transferred > 0) {
                buffer->resize(bytes_transferred);
                std::cout << "Received TCP data from client " << static_cast<int>(id) << ": "
                          << std::string(buffer->begin(), buffer->end()) << std::endl;
                // Process the received data here
                receive_tcp_data(tcp_socket, id); // Continue reading data from the client
            } else if (error) {
                std::cerr << "Error (receive tcp): " << error.message() << std::endl;
                // Handle the error, e.g., remove the client from the list
                _tcp_sockets.erase(id);
            }
        }
    );
}


void Network::Server::receive_tcp_data() {
    for (auto& [id, socket] : _tcp_sockets) {
        auto buffer = std::make_shared<std::vector<uint8_t>>(1024); // Adjust the buffer size as needed

        socket.get()->async_read_some(asio::buffer(*buffer),
            [this, socket, buffer, id](const asio::error_code& error, std::size_t bytes_transferred) {
                if (!error && bytes_transferred > 0) {
                    buffer->resize(bytes_transferred);
                    std::cout << "Received TCP data from client " << static_cast<int>(id) << ": "
                              << std::string(buffer->begin(), buffer->end()) << std::endl;
                    // Continue reading data from the client
                    receive_tcp_data();
                } else if (error) {
                    std::cerr << "Error (receive tcp): " << error.message() << std::endl;
                    // Handle the error, e.g., remove the client from the list
                    _tcp_sockets.erase(id);
                }
            }
        );
    }
}

void Network::Server::receive_data() {
    _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint,
        [this](const asio::error_code& error, const std::size_t rc_bytes) {
            if (!error && rc_bytes > 0) {
                try {
                    const std::string message(_recv_buffer.begin(), _recv_buffer.begin() + rc_bytes);
                    std::cout << "Received: " << message << std::endl;
                    if (int8_t sender_id = find_sender_id_udp(_remote_endpoint); sender_id != -1) {
                        _recv_queue.push({{sender_id, std::vector<uint8_t>(_recv_buffer.begin(), _recv_buffer.begin() + rc_bytes)}});
                    } else {
                        std::cerr << "Unknown sender" << std::endl;
                    }
                } catch (std::exception& e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
            }
            receive_data();
        }
    );
}


int8_t Network::Server::find_sender_id_udp(const asio::ip::udp::endpoint& endpoint) const {
    for (const auto& client : _clients) {
        if (client.second == endpoint) {
            return client.first;
        }
    }
    return -1;
}

std::vector<uint8_t> Network::Server::get_recv_buffer() const {
    return _recv_buffer;
}

Network::Server::~Server()
{
    Server::stop();
    std::cout << "Server stopped" << std::endl;
}

std::string Network::Server::getHostIP() {
    return asio::ip::host_name();
}

int8_t Network::Server::create_client_id() {
    static int8_t id = 0;
    return id++;
}
