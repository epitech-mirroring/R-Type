/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#ifndef MESSAGETYPE_HPP
#define MESSAGETYPE_HPP

#include <cstdint>

/**
 * @enum MessageType for tcp send/receive
 * @brief All the possible type of message for the tcp
 * @version v0.1.0
 * @since v0.1.0
 * @author Simon GANIER-LOMBARD
 */
enum MessageType : std::uint8_t {
    NO_MESSAGE_TYPE,
    EXIT,
    PING,
    PONG,
    SHUTDOWN,
};

#endif //MESSAGETYPE_HPP
