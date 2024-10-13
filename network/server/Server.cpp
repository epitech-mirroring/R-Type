/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include "../../server/Server.hpp"

#include <cstdint>
#include <iostream>
#include <asio.hpp>

//-------------------------------------Constructor------------------------------------------
Network::Server::Server(unsigned short TCP_port, unsigned short UDP_port)
    :_io_context(), _acceptor(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), TCP_port)),
      _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), UDP_port)) {
    _TCP_port = TCP_port;
    _UDP_port = UDP_port;
    _recv_buffer.resize(1024);
    _send_timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(1));
}

//-------------------------------------Initiator------------------------------------------
void Network::Server::start(RType::Server *server) {
    std::cout << "Server started, TCP port " << _TCP_port << " UDP port " << _UDP_port << std::endl;
    connect_new_client(server);
    receive_udp_data();
    //send_udp_data_loop(); //Todo fix me
    const auto serverStartedMessage = std::make_shared<ServerStarted>("Server has started successfully");
    _internal_queue.push(serverStartedMessage);
    _io_context.run(); // run the io_context event loop for asynchronous operations (non-blocking)
}

void Network::Server::connect_new_client(RType::Server *server) {
    auto socket = std::make_shared<asio::ip::tcp::socket>(_io_context);

    // Accept new client connection in TCP
    _acceptor.async_accept(*socket, [this, socket, server](const asio::error_code& error) {
        if (!error) {
            int id = server->createNewPlayer();
            _tcp_sockets[id] = socket;
            auto clientConnectedMessage = std::make_shared<ClientConnected>("Client connected with id: " + std::to_string(id), id);
            std::cout << "TCP client, id: " << id << std::endl;

            // Wait for UDP connection from the same client
            asio::write(*_tcp_sockets[id], asio::buffer(&id, sizeof(id)));

            _socket.receive_from(asio::buffer(_recv_buffer), _remote_endpoint);
            _clients[id] = _remote_endpoint;
            std::cout << "UDP client, id: " << id << std::endl;

            receive_tcp_data(socket, id);
            connect_new_client(server);
        }
    });
}

// -------------------------------------UDP methods------------------------------------------

void Network::Server::send_udp_data_loop() {
    _send_data_handler = [this](const asio::error_code& error) {
        if (!error) {
            send_udp_data();
            _send_timer->expires_after(std::chrono::milliseconds(1));
            _send_timer->async_wait(_send_data_handler);
        }
    };
    _send_timer->async_wait(_send_data_handler);
}


void Network::Server::add_to_udp_send_queue(const std::vector<char>& data, int id)
{
    _send_queue.push({{id, data}});
}

void Network::Server::send_udp_data() {
    if (!_send_queue.empty()) {
        if (auto data = _send_queue.front(); _clients.find(data.begin()->first) != _clients.end()) {
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

void Network::Server::send_udp_data(const std::vector<char>& data, int id) {
    if (_clients.find(id) != _clients.end()) {
        _socket.async_send_to(asio::buffer(data), _clients[id],
            [this](const asio::error_code& error, std ::size_t bytes_transferred) {
                if (error) {
                    std::cerr << "Error (send udp): " << error.message() << std::endl;
                }
            }
        );
    }
}

void Network::Server::receive_udp_data() {
    _socket.async_receive_from(asio::buffer(_recv_buffer), _remote_endpoint,
        [this](const asio::error_code& error, const std::size_t rc_bytes) {
            if (!error && rc_bytes > 0) {
                try {
                    if (int8_t sender_id = find_sender_id_udp(_remote_endpoint); sender_id != -1) {
                        _recv_queue.push({{sender_id, std::vector<char>(_recv_buffer.begin(), _recv_buffer.begin() + rc_bytes)}});
                    } else {
                        std::cerr << "Unknown sender" << std::endl;
                    }
                } catch (std::exception& e) {
                    std::cerr << "Exception: " << e.what() << std::endl;
                }
            }
            receive_udp_data();
        }
    );
}

int Network::Server::find_sender_id_udp(const asio::ip::udp::endpoint& endpoint) const {
    for (const auto& client : _clients) {
        if (client.second == endpoint) {
            return client.first;
        }
    }
    return -1;
}

std::unordered_map<int, std::vector<char>> Network::Server::get_next_recv_queue()
{
    if (!_recv_queue.empty()) {
        auto data = _recv_queue.front();
        _recv_queue.pop();
        return data;
    }
    return {};
}

size_t Network::Server::get_size_recv_queue()
{
    return _recv_queue.size();
}

std::vector<int> Network::Server::get_connected_clients() const
{
    std::vector<int> connected_clients;
    for (const auto&[id, tcp_clients] : _clients) {
        connected_clients.push_back(id);
    }
    return connected_clients;
}

//-------------------------------------TCP methods------------------------------------------

void Network::Server::receive_tcp_data(const std::shared_ptr<asio::ip::tcp::socket>& tcp_socket, int id)
{
    auto buffer = std::make_shared<std::vector<char>>(1024);

    tcp_socket->async_read_some(asio::buffer(*buffer),
        [this, tcp_socket, buffer, id](const asio::error_code& error, std::size_t bytes_transferred) {
            if (!error && bytes_transferred > 0) {
                buffer->resize(bytes_transferred);
                std::string message(buffer->begin(), buffer->begin() + bytes_transferred);
                if(message == "exit") {
                    //close the socket
                    std::cout << "Client disconnected with id: " << static_cast<int>(id) << std::endl;
                    _tcp_sockets[id]->close();
                    _clients.erase(id);
                    _tcp_sockets.erase(id);
                    return;
                }
                receive_tcp_data(tcp_socket, id); // Continue reading data from the client
            } else if (error) {
                std::cerr << "Client disconnected with id: " << static_cast<int>(id) << std::endl;
                _clients.erase(id);
                _tcp_sockets.erase(id);
            }
        }
    );
}

void Network::Server::send_exit_message(int id) {
    if (_tcp_sockets.find(id) != _tcp_sockets.end()) {
        asio::write(*_tcp_sockets[id], asio::buffer("exit\n"));
    }
}

void Network::Server::send_exit_message() {
    for (const auto&[id, tcp_socket] : _tcp_sockets) {
        asio::write(*tcp_socket, asio::buffer("exit\n"));
    }
}

//-------------------------------------Destructor------------------------------------------
void Network::Server::stop() {
    _io_context.stop();
    for (int i = 0; i < _clients.size(); i++) {
        if (_tcp_sockets[i]->is_open()) {
            _tcp_sockets[i]->close();
        }
    }
    if (_socket.is_open()) {
        _socket.close();
    }
}

Network::Server::~Server()
{
    Server::stop();
    std::cout << "Server stopped" << std::endl;
}

//-------------------------------------Getters------------------------------------------
std::string Network::Server::getHostIP() {
    return asio::ip::host_name();
}

int Network::Server::create_client_id() {
    static int id = 0;
    return id++;
}
