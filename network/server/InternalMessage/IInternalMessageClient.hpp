/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#ifndef ICLIENTINTERNALMESSAGE_HPP
#define ICLIENTINTERNALMESSAGE_HPP

#include <chrono>
#include "IInternalMessage.hpp"

/**
 * @class IInternalMessageClient
 * @brief Interface for internal client messages
 * @details This interface class defines the methods for handling internal client messages, including getting the message content and client ID.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class IInternalMessageClient : public IInternalMessage {
public:
    /**
     * @brief Destructor
     * @version 0.1.0
     * @since 0.1.0
     */
    ~IInternalMessageClient() override = default;

    /**
     * @brief Gets the message content
     * @return The message content
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] std::string getMessage() const override = 0;

    /**
     * @brief Gets the client ID
     * @return The client ID
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] virtual int getId() const = 0;
};

#endif //ICLIENTINTERNALMESSAGE_HPP
