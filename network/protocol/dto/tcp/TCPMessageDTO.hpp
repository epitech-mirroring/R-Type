/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#ifndef TCPMESSAGEDTO_HPP
#define TCPMESSAGEDTO_HPP
#include "ATCPDTO.hpp"

/**
 * @class TCPMessageDTO
 * @brief Data Transfer Object for TCP messages
 * @details This class is used to handle the serialization and deserialization of TCP messages.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class TCPMessageDTO: public ATCPDTO {
public:
    /**
     * @brief Default constructor
     * @details This constructor initializes the TCPMessageDTO with default values.
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    TCPMessageDTO();

    /**
     * @brief Parameterized constructor
     * @details This constructor initializes the TCPMessageDTO with a client ID and message type.
     * @param client_id The ID of the client
     * @param type The type of the message
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    TCPMessageDTO(int client_id, MessageType type);

    /**
     * @brief Destructor
     * @details Default destructor for TCPMessageDTO.
     * @version 0.1.0
     * @since 0.1.0
     */
    ~TCPMessageDTO() override = default;

    /**
     * @brief Clone the DTO
     * @details Creates a copy of the current TCPMessageDTO object.
     * @return A pointer to the cloned IDTO object
     * @version 0.1.0
     * @since 0.1.0
     */
    IDTO *clone() override;

    /**
     * @brief Deserialize TCP data
     * @details Converts a vector of characters into a TCPMessageDTO object.
     * @param data The vector of characters to deserialize
     * @version 0.1.0
     * @since 0.1.0
     */
    void deserializeTCP(std::vector<char> &data) override;

    /**
     * @brief Serialize TCP data
     * @details Converts the TCPMessageDTO object into a vector of characters.
     * @return A vector of characters representing the serialized data
     * @version 0.1.0
     * @since 0.1.0
     */
    std::vector<char> serializeTCP() override;

    /**
     * @brief Set the message type
     * @details Sets the type of the TCP message.
     * @param type The type of the message
     * @version 0.1.0
     * @since 0.1.0
     */
    void setType(MessageType type);

    /**
     * @brief Get the message type
     * @details Retrieves the type of the TCP message.
     * @return The type of the message
     * @version 0.1.0
     * @since 0.1.0
     */
    [[nodiscard]] MessageType getType() const;

private:
    MessageType _type; ///< The type of the TCP message
};

#endif //TCPMESSAGEDTO_HPP
