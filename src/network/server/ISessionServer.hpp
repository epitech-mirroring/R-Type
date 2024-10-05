/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/


#ifndef ISESSIONSERVER_HPP
#define ISESSIONSERVER_HPP

#include <asio.hpp>

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
  using callback = std::function<void(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint)>;
 public:
  /**
   * @brief Starts the server listening for incoming connections
   * @param function The callback function to handle received data
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void start(callback function) = 0;

  /**
   * @brief Stops the server and closes all connections
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void stop() = 0;

  /**
   * @brief Sends data to a client
   * @param data The data to send
   * @param client_endpoint The client endpoint to send the data to
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void send_data(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint) = 0;

  /**
   * @brief Receives data from a client
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void receive_data() = 0;

  /**
   * @brief Destructor
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual ~ISessionServer() = default;

 };
}

#endif //ISESSIONSERVER_HPP
