/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <asio.hpp>
#include <vector>

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
     * @class Client
     * @brief Represents a network client
     * @details This class handles the network client operations such as connecting, sending, receiving, and disconnecting.
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    class Client {

    using callback = std::function<void(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint)>;
    public:
        /**
         * @brief Constructs a new network client object
         * @param host The host address to connect to
         * @param udp_port The UDP port to use
         * @param tcp_port The TCP port to use
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        Client(std::string host, unsigned short udp_port, unsigned short tcp_port);

        /**
         * @brief Destroys the network client object
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        ~Client();

        /**
         * @brief Connects to the server with tcp and udp sockets
         * @param function The callback function to handle received data
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void connect(callback function);

        /**
         * @brief Sends data to the server with udp socket
         * @param data The data to send
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void send(const std::vector<uint8_t> &data);

        /**
         * @brief Receives data from the server with udp socket
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void receive();

        /**
         * @brief Disconnects from the client from the server
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void disconnect();

    private:
        std::string _host; ///< The host address
        unsigned short _TCP_PORT; ///< The TCP port
        unsigned short _UDP_PORT; ///< The UDP port

        asio::io_context _io_context; ///< The IO context
        asio::ip::udp::socket _udp_socket; ///< The UDP socket
        asio::ip::tcp::socket _tcp_socket; ///< The TCP socket
        asio::ip::udp::endpoint _endpoint; ///< The UDP endpoint

        int8_t _id; ///< The client ID
        std::vector<uint8_t> _recv_buffer; ///< The receive buffer
        callback _callback; ///< The callback function
    };
}

#endif // CLIENT_HPP
