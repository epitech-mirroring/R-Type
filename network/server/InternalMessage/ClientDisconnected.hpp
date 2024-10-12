/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef CLIENTDISCONNECTED_HPP
#define CLIENTDISCONNECTED_HPP

#include <utility>
#include "IInternalMessageClient.hpp"

/**
 * @class ClientDisconnected
 * @brief Represents a client disconnection message
 * @details This class handles the client disconnection message, including the message content and client ID.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class ClientDisconnected final : public IInternalMessageClient {
public:
 /**
  * @brief Constructor
  * @param message The disconnection message
  * @param id The client ID
  * @version 0.1.0
  * @since 0.1.0
  */
 ClientDisconnected(std::string message, const uint8_t id) : _message(std::move(message)), _id(id) {}

 /**
  * @brief Destructor
  * @version 0.1.0
  * @since 0.1.0
  */
 ~ClientDisconnected() override = default;

 /**
  * @brief Gets the client ID
  * @return The client ID
  * @version 0.1.0
  * @since 0.1.0
  */
 [[nodiscard]] int getId() const override;

 /**
  * @brief Gets the disconnection message
  * @return The disconnection message
  * @version 0.1.0
  * @since 0.1.0
  */
 [[nodiscard]] std::string getMessage() const override;

private:
 std::string _message; ///< The disconnection message
 uint8_t _id; ///< The client ID
 std::chrono::time_point<std::chrono::system_clock> _time; ///< The time of the disconnection
};

#endif // CLIENTDISCONNECTED_HPP
