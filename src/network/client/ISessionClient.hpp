/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want ! handles the network client operations such as connecting, sending, receiving, and disconnecting.
*/

#ifndef ISESSIONCLIENT_HPP
#define ISESSIONCLIENT_HPP

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
  * @class ISessionClient
  * @brief Represents a network client
  * @details This interface class handles the network client operations such as connecting, sending, receiving, and disconnecting.
  * @version 0.1.0
  * @since 0.1.0
  * @author Simon GANIER-LOMBARD
  */
 class ISessionClient {
  using callback = std::function<void(const std::vector<uint8_t> &data, const asio::ip::udp::endpoint &client_endpoint)>;
 public:
  /**
   * @brief Connects to the server with tcp and udp sockets
   * @param function The callback function to handle received data
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void connect(callback function) = 0;

  /**
   * @brief Sends data to the server
   * @param data The data to send
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void send_data(const std::vector<uint8_t> &data) = 0;

  /**
   * @brief receive data from the server
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void receive_data() = 0;

  /**
   * @brief Stops the client and closes all connections
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void stop() = 0;

  /**
   * @brief Destructor
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual ~ISessionClient() = default;
 };
}

#endif //ISessionClient_HPP
