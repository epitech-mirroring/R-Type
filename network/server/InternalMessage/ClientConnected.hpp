/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef CLIENTCONNECTED_HPP
#define CLIENTCONNECTED_HPP

#include <utility>
#include "IInternalMessageClient.hpp"

/**
 * @class ClientConnected
 * @brief Represents a client connection message
 * @details This class handles the client connection message, including the message content and client ID.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class ClientConnected final : public IInternalMessageClient {
public:
    /**
     * @brief Constructor
     * @param message The connection message
     * @param id The client ID
     * @version 0.1.0
     * @since 0.1.0
     */
    ClientConnected(std::string message, const uint8_t id) : _message(std::move(message)), _id(id) {}

    /**
     * @brief Destructor
     * @version 0.1.0
     * @since 0.1.0
     */
    ~ClientConnected() override = default;

    /**
     * @brief Gets the client ID
     * @return The client ID
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] int getId() const override;

    /**
     * @brief Gets the connection message
     * @return The connection message
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] std::string getMessage() const override;

private:
    std::string _message; ///< The connection message
    std::uint8_t _id; ///< The client ID
    std::chrono::time_point<std::chrono::system_clock> _time; ///< The time of the connection
};

#endif // CLIENTCONNECTED_HPP
