/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/


#ifndef ISESSIONSERVER_HPP
#define ISESSIONSERVER_HPP

#ifdef _WIN32
#define _WIN32_WINNT 0x0601
#endif

#include <asio.hpp>

namespace RType {
 class Server; // Forward declaration
}

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
  * @class ISessionServer
  * @brief Represents a network server
  * @details This interface class handles the network server operations such as starting, stopping, sending, and receiving data.
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */
 class ISessionServer {
 public:
  /**
   * @brief Starts the server listening for incoming connections
   * @param function The callback function to handle received data
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void start(RType::Server *server) = 0;

  /**
   * @brief Stops the server and closes all connections
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void stop() = 0;

  /**
 * @brief Sends data to a client in UDP
 * @param data The data to send
 * @param id The id of the client
 * @param client_endpoint The client endpoint to send the data to
 * @version 0.1.0
 * @since 0.1.0
 */
  virtual void  add_to_udp_send_queue(const std::vector<char> &data, int id) = 0;

  /**
   * @brief Get the next receive queue data
   * @return The receive queue data
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual std::unordered_map<int, std::vector<char>> get_next_recv_queue() = 0;

  /**
   * @brief Get the size of the receive queue
   * @return The size of the receive queue
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual size_t get_size_recv_queue() = 0;

  /**
 * @brief Sends data to a client in UDP
 * @param data The data to send
 * @param client_endpoint The client endpoint to send the data to
 * @version 0.1.0
 * @since 0.1.0
 */
  virtual void send_udp_data() = 0;

  /**
   * @brief Receives data from a client
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void receive_udp_data() = 0;

  /**
   * @brief Destructor
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual ~ISessionServer() = default;

  /**
   * @brief Init the tcp socket of the server
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void connect_new_client(RType::Server *server) = 0;

  /**
   *
   * @brief Ge all the list of conneted client to the server
   * @return The list of connected clients
   * @version 0.1.0
   * @since 0.1.0
   * @author Simon GANIER-LOMBARD
   */
   virtual std::vector<int> get_connected_clients() const = 0;

   /**
  * @brief Finds the sender ID from the endpoint
  * @param endpoint The endpoint to find the ID for
  * @return The ID of the sender
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */
   virtual int find_sender_id_udp(const asio::ip::udp::endpoint& endpoint) const = 0 ;

  /**
   * @brief Send data to the tcp socket
   * @param tcp_socket The tcp socket to send the data to
   * @param id The id of the client
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void receive_tcp_data(const std::shared_ptr<asio::ip::tcp::socket> &tcp_socket, int id) = 0;

 };
}

#endif //ISESSIONSERVER_HPP
