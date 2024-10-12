/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef SERVERSTARTED_HPP
#define SERVERSTARTED_HPP

#include <chrono>
#include <utility>
#include "IInternalMessageClient.hpp"

/**
 * @class ServerStarted
 * @brief Represents a server started message
 * @details This class handles the server started message, including the message content and the time of the event.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class ServerStarted final : public IInternalMessage {
public:
    /**
     * @brief Constructor
     * @param message The server started message
     * @version 0.1.0
     * @since 0.1.0
     */
    explicit ServerStarted(std::string message) : _message(std::move(message)) {}

    /**
     * @brief Destructor
     * @version 0.1.0
     * @since 0.1.0
     */
    ~ServerStarted() override = default;

    /**
     * @brief Gets the server started message
     * @return The server started message
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] std::string getMessage() const override;

private:
    std::string _message; ///< The server started message
    std::chrono::time_point<std::chrono::system_clock> _time; ///< The time of the server start
};

#endif //SERVERSTARTED_HPP
