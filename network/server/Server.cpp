/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there, just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Server.hpp"
#include "../../server/Server.hpp"



//-------------------------------------Constructor------------------------------------------
Network::Server::Server(const unsigned short TCP_port, const unsigned short UDP_port)
    :_TCP_port(TCP_port), _UDP_port(UDP_port), _acceptor(_io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), TCP_port)),
      _socket(_io_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), UDP_port)) {
    _send_timer = std::make_shared<asio::steady_timer>(_io_context, std::chrono::milliseconds(1));
    auto *registry = new DTORegistry();
    _encoder = new DTOEncoder(registry);
    _decoder = new DTODecoder(registry);
}

//-------------------------------------Initiator------------------------------------------
void Network::Server::start(RType::Server *server)
{
    std::cout << "Server started, TCP port " << _TCP_port << " UDP port " << _UDP_port << '\n';
    connect_new_client(server);
    receive_udp_data();
    const auto serverStartedMessage = std::make_shared<ServerStarted>("Server has started successfully");
    _internal_queue.push(serverStartedMessage);
    _io_context.run(); // run the io_context event loop for asynchronous operations (non-blocking)
}

void Network::Server::connect_new_client(RType::Server *server)
{
    auto socket = std::make_shared<asio::ip::tcp::socket>(_io_context);

    // Accept new client connection in TCP
    _acceptor.async_accept(*socket, [this, socket, server](const asio::error_code& error) {
        if (!error) {
            int const client_id = server->createNewPlayer();
            _tcp_sockets[client_id] = socket;
            auto clientConnectedMessage = std::make_shared<ClientConnected>("Client connected with id: " + std::to_string(client_id), client_id);

            send_client_id(client_id);
            get_udp_endpoints(client_id);
            _internal_queue.push(clientConnectedMessage);

            std::cout << "UDP client, id: " << client_id << '\n';

            receive_tcp_data(client_id);
            connect_new_client(server);
        }
    });
}

// -------------------------------------UDP methods------------------------------------------

void Network::Server::send_udp_data_loop()
{
    _send_data_handler = [this](const asio::error_code& error) {
        if (!error) {
            send_udp_data();
            _send_timer->expires_after(std::chrono::milliseconds(1));
            _send_timer->async_wait(_send_data_handler);
        }
    };
    _send_timer->async_wait(_send_data_handler);
}


void Network::Server::add_to_udp_send_queue(const std::vector<char>& data, int client_id)
{
    _send_queue.push({{client_id, data}});
}

void Network::Server::send_udp_data()
{
    if (!_send_queue.empty()) {
        if (auto data = _send_queue.front(); _clients.find(data.begin()->first) != _clients.end()) {
            _socket.async_send_to(asio::buffer(data.begin()->second), _clients[data.begin()->first],
                [this](const asio::error_code& error, std ::size_t  /*bytes_transferred*/) {
                    if (error) {
                        std::cerr << "Error (send udp): " << error.message() << '\n';
                    }
                }
            );
        }
        _send_queue.pop();
    }
}

void Network::Server::send_udp_data(const std::vector<char>& data, const int client_id)
{
    if (_clients.find(client_id) != _clients.end()) {
        _socket.async_send_to(asio::buffer(data), _clients[client_id],
            [this](const asio::error_code& error, std ::size_t  /*bytes_transferred*/) {
                if (error) {
                    std::cerr << "Error (send udp): " << error.message() << '\n';
                }
            }
        );
    }
}

void Network::Server::receive_udp_data()
{
    _socket.async_receive_from(_recv_buffer.prepare(512), _remote_endpoint,
        [this](const asio::error_code& error, const std::size_t rc_bytes) {
            if (!error && rc_bytes > 0) {
                _recv_buffer.commit(rc_bytes);
                try {
                    if (int sender_id = find_sender_id_udp(_remote_endpoint); sender_id != -1) {
                        std::istream ist(&_recv_buffer);
                        std::vector<char> data((std::istreambuf_iterator<char>(ist)), std::istreambuf_iterator<char>());
                        _recv_queue.push({{sender_id, std::move(data)}});
                    } else {
                        std::cerr << "Unknown sender" << '\n';
                    }
                } catch (std::exception& e) {
                    std::cerr << "Exception: " << e.what() << '\n';
                }
            }
            receive_udp_data();
        }
    );
}

int Network::Server::find_sender_id_udp(const asio::ip::udp::endpoint& endpoint) const
{
    for (const auto& [clientId,clientEndpoint] : _clients) {
        if (clientEndpoint == endpoint) {
            return clientId;
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

void Network::Server::receive_tcp_data(int client_id)
{
    auto socket = _tcp_sockets[client_id];
    std::vector<char> data(PACKET_MAX_SIZE);
    asio::async_read(*socket, asio::buffer(data),
        [this, client_id, socket, data](const asio::error_code& error, std::size_t rc_bytes) {
            if (!error && rc_bytes > 0) {
                TCPPacket packet;
                packet.setPacket(data);
                auto data_packet = packet.getPayloadContent();
                auto *dto = _decoder->decode(data_packet);
                auto *tcp_message_dto = dynamic_cast<TCPMessageDTO *>(dto);
                auto type = tcp_message_dto->getType();
                if (type == EXIT || type == SHUTDOWN) {
                    _clients.erase(client_id);
                    _tcp_sockets.erase(client_id);
                }
                receive_tcp_data(client_id);
            }
        }
    );
}

void Network::Server::send_tcp_data(int client_id, MessageType type)
{
    TCPPacket packet;

    IDTO *tcp_message_dto = new TCPMessageDTO(client_id, type);
    std::vector<char> const data = _encoder->encode(*tcp_message_dto);
    packet.setPayloadContent(data, data.size());

    asio::write(*_tcp_sockets[client_id], asio::buffer(packet.getPacket()));
}

void Network::Server::send_client_id(int client_id)
{
    TCPPacket packet;

    IDTO *client_id_dto = new TCPSendIdDTO(client_id);
    std::vector<char> const data = _encoder->encode(*client_id_dto);
    packet.setPayloadContent(data, data.size());

    asio::write(*_tcp_sockets[client_id], asio::buffer(packet.getPacket()));
}

void Network::Server::get_udp_endpoints(int client_id)
{

    std::vector<char> data(PACKET_MAX_SIZE);
    asio::read(*_tcp_sockets[client_id], asio::buffer(data));
    TCPPacket packet;
    packet.setPacket(data);
    auto data_packet = packet.getPayloadContent();
    auto *dto = _decoder->decode(data_packet);
    auto *udp_endpoint_dto = dynamic_cast<TCPCreateUDPEndpointDTO *>(dto);
    _clients[client_id] = udp_endpoint_dto->getEndpoint();
}

//-------------------------------------Destructor------------------------------------------
void Network::Server::stop()
{
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
    std::cout << "Server stopped" << '\n';
}

//-------------------------------------Getters------------------------------------------
std::string Network::Server::getHostIP()
{
    return asio::ip::host_name();
}
