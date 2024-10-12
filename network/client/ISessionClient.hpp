/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want ! handles the network client operations such as connecting, sending, receiving, and disconnecting.
*/

#ifndef ISESSIONCLIENT_HPP
#define ISESSIONCLIENT_HPP

#ifdef _WIN32
#define _WIN32_WINNT 0x0601
#endif

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
 public:
  /**
   * @brief Connects to the server with tcp and udp sockets
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void connect() = 0;

  /**
   * @brief Sends data to the server
   * @param data The data to send
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void send_udp_data(const std::vector<char> &data) = 0;

  /**
   * @brief receive data from the server
   * @version 0.1.0
   * @since 0.1.0
   */
  virtual void receive_udp_data() = 0;

     /**
    * @brief Receives data from the server with tcp socket
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
     virtual void receive_tcp_data() = 0 ;
     /**
      *
     * @brief Sends data to the server with tcp socket
     * @param data The data to send
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
     virtual void send_tcp_data(const std::string& data) = 0;

     /**
      * @brief Sends data to a client with a specific ID in UDP mode
      * @param data The data to send
      * @param id The ID of the client to send data to
      * @version 0.1.0
      * @since 0.1.0
      * @author Simon GANIER-LOMBARD
      */
     virtual void add_to_send_queue(const std::vector<char> &data) = 0;


     /**
     * @brief Get the next receive queue data
     * @return The receive queue data
     * @version 0.1.0
     * @since 0.1.0
     */
      virtual std::vector<char> get_next_recv_queue() = 0;

      /**
       * @brief Get the size of the receive queue
       * @return The size of the receive queue
       * @version 0.1.0
       * @since 0.1.0
       */
     virtual std::uint8_t get_size_recv_queue() = 0 ;



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
