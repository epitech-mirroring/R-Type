/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef SERVER_HPP
#define SERVER_HPP

#include <asio.hpp>
#include <queue>
#include <vector>
#include <unordered_map>
#include "ISessionServer.hpp"
#include "InternalMessage/ClientConnected.hpp"
#include "InternalMessage/ClientDisconnected.hpp"
#include "InternalMessage/ServerStarted.hpp"

/**
 * @namespace Network
 * @brief Main namespace for the network library
 * @details This namespace contains all the classes, functions and enums for the network library
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
namespace Network {

    /**
     * @class Server
     * @brief Represents a network server
     * @details This class handles the network server operations such as starting, stopping, sending, and receiving data.
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    class Server: public ISessionServer {
        using callback = std::function<void(const std::vector<char> &data,
         const asio::ip::udp::endpoint &client_endpoint)>;
        public:
            /**
             * @brief Constructs a new Server object
             * @param TCP_port The TCP port to use
             * @param UDP_port The UDP port to use
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            explicit Server(unsigned short TCP_port, unsigned short UDP_port);

            /**
             * @brief Destroys the Server object
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            ~Server() override;

            /**
             * @brief Starts the server listening for incoming connections
             * @param function The callback function to handle received data
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void start() override;

            /**
             * @brief Stops the server and closes all connections
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void stop() override;

            /**
             * @brief Sends data to a client with a specific ID in UDP mode
             * @param data The data to send
             * @param id The ID of the client to send data to
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void add_to_udp_send_queue(const std::vector<char> &data, uint8_t id) override;

            /**
             * @brief Sends data to a client in UDP mode from the send queue if not empty
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void send_udp_data() override;

            /**
             * @brief Initializes the server tcp socket
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void connect_new_client() override;

            /**
             * @brief Reads data from a TCP connection
             * @param tcp_socket The TCP socket to read from
             * @param id The client ID
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */

            void receive_tcp_data(const std::shared_ptr<asio::ip::tcp::socket>& tcp_socket, int8_t id) override;

            /**
             * @brief Receives data from a UDP connection
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            void receive_udp_data() override;

           /**
            * @brief Get the next receive queue data
            * @return The receive queue data
            * @version 0.1.0
            * @since 0.1.0
            */
            std::unordered_map<std::int8_t, std::vector<char>> get_next_recv_queue() override;

           /**
            * @brief Get the size of the receive queue
            * @return The size of the receive queue
            * @version 0.1.0
            * @since 0.1.0
            */
            std::uint8_t get_size_recv_queue() override;


    private:
           /**
            * @brief Creates a new client ID
            * @return The new client ID
            * @version 0.1.0
            * @since 0.1.0
            * @author Simon GANIER-LOMBARD
            */
            void send_udp_data_loop();

            /**
             * @brief Creates a new client ID
             * @return The new client ID
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            static int8_t create_client_id();

           /**
            * @brief Gets the host IP address
            * @return The host IP address on the current network
            * @version 0.1.0
            * @since 0.1.0
            * @author Simon GANIER-LOMBARD
            */
            static std::string getHostIP() ;

            /**
             * @brief Finds the sender ID from the endpoint
             * @param endpoint The endpoint to find the ID for
             * @return The ID of the sender
             * @version 0.1.0
             * @since 0.1.0
             * @author Simon GANIER-LOMBARD
             */
            int8_t find_sender_id_udp(const asio::ip::udp::endpoint& endpoint) const;

            // add element to the recv queue
            // consume element on the recv queue
            // add element to the send queue
            // consume element on the send queue

            unsigned short _TCP_port; ///< The TCP port
            unsigned short _UDP_port; ///< The UDP port

            asio::io_context _io_context; ///< The IO context
            asio::ip::tcp::acceptor _acceptor; ///< The TCP acceptor for incoming connections
            asio::ip::udp::socket _socket; ///< The UDP socket for incoming connections

            std::shared_ptr<asio::steady_timer> _send_timer; ///< The send
            std::function<void(const asio::error_code&)> _send_data_handler; ///< The send data handler

            std::queue<std::unordered_map<std::int8_t, std::vector<char>>> _send_queue; ///< The send queue id and data
            std::queue<std::unordered_map<std::int8_t, std::vector<char>>> _recv_queue; ///< The receive queue id and data
            std::queue<std::shared_ptr<IInternalMessage>> _internal_queue; ///< The internal message queue

            std::unordered_map<std::int8_t, std::shared_ptr<asio::ip::tcp::socket>> _tcp_sockets; ///< The TCP sockets map with their ID and socket
            std::unordered_map<std::int8_t, asio::ip::udp::endpoint> _clients; ///< The clients map with their ID and endpoint
            std::vector<uint8_t> _recv_buffer; ///< The receive buffer for incoming data
            asio::ip::udp::endpoint _remote_endpoint; ///< The remote endpoint
    };
}

#endif // SERVER_HPP
