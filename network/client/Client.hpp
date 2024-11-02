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
#include <queue>
#include "ISessionClient.hpp"
#include "protocol/dto/DTOEncoder.hpp"
#include "protocol/dto/DTODecoder.hpp"
#include "protocol/dto/tcp/TCPSendIdDTO.hpp"
#include "protocol/packet/TCPPacket.hpp"
#include "protocol/dto/tcp/TCPCreateUDPEndpointDTO.hpp"

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
    class Client final: public ISessionClient {

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
        ~Client() override;

        /**
         * @brief Connects to the server with tcp and udp sockets
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void connect() override;

        /**
         * @brief Sends data to the server with udp socket
         * @param data The data to send
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void send_udp_data(const std::vector<char> &data) override;

        /**
         * @brief Receives data from the server with udp socket
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void receive_udp_data() override;

        /**
         * @brief Receives data from the server with tcp socket
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
         void receive_tcp_data() override;

        /**
        *
        * @brief Sends data to the server with tcp socket
        * @param data The data to send
        * @version 0.1.0
        * @since 0.1.0
        * @author Simon GANIER-LOMBARD
        */
        void send_tcp_data(const std::string& data) override;

        /**
         * @brief Sends data to a client with a specific ID in UDP mode
         * @param data The data to send
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void add_to_send_queue(const std::vector<char> &data ) override;


         /**
         * @brief Get the next receive queue data
         * @return The receive queue data
         * @version 0.1.0
         * @since 0.1.0
         */
          std::vector<char> get_next_recv_queue() override;

         /**
          * @brief Get the size of the receive queue
          * @return The size of the receive queue
          * @version 0.1.0
          * @since 0.1.0
          */
         size_t get_size_recv_queue() override;


        /**
         * @brief Disconnects from the client from the server
         * @version 0.1.0
         * @since 0.1.0
         * @author Simon GANIER-LOMBARD
         */
        void stop() override;

        /**
         * @brief Get the client ID
         * @return The client ID
         * @version 0.1.0
         * @since 0.1.0
         * @author Landry GIGANT
         */
        [[nodiscard]] int getId() const;

    private:

        /**
         * @brief Indicates if the client is alive
         * @return True if the client is alive, false otherwise
         * @version 0.1.0
         * @since 0.1.0
         */
        [[nodiscard]] bool is_alive() const;

       /**
        * @brief Sends data to the server with udp socket
        * @version 0.1.0
        * @since 0.1.0
        */
        void send_udp_data_loop();

        std::string _host; ///< The host address
        unsigned short _TCP_PORT; ///< The TCP port
        unsigned short _UDP_PORT; ///< The UDP port

        asio::io_context _io_context; ///< The IO context
        asio::ip::udp::socket _udp_socket; ///< The UDP socket
        asio::ip::tcp::socket _tcp_socket; ///< The TCP socket
        asio::ip::udp::endpoint _endpoint; ///< The UDP endpoint
        asio::ip::tcp::endpoint _tcp_endpoint; ///< The TCP endpoint

        std::queue<std::vector<char>> _send_queue; ///< The send queue
        std::queue<std::vector<char>> _recv_queue; ///< The receive queue

        std::shared_ptr<asio::steady_timer> _send_timer; ///< The send
        std::function<void(const asio::error_code&)> _send_data_handler; ///< The send data handler

        int _id; ///< The client ID
        asio::streambuf _recv_udp_buffer;
        asio::streambuf _recv_tcp_buffer;
        std::thread _io_thread; ///< The IO thread
        bool _is_alive; ///< Indicates if the client is alive

        IDTOEncoder *_encoder; ///< The DTO encoder
        IDTODecoder *_decoder; ///< The DTO decoder
    };
}

#endif // CLIENT_HPP
