/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#ifndef TCPSENDID_HPP
#define TCPSENDID_HPP

#include "ATCPDTO.hpp"
/**
 * @class TCPSendIdDTO
 * @brief Exception class for network errors
 * @details This class is used to define the network errors
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class TCPSendIdDTO : public IDTO {
public:
    /**
    * @brief Constructor with client ID
    * @param client_id The ID of the client
    * @details This constructor initializes the TCPSendIdDTO with the given client ID.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    TCPSendIdDTO(int client_id);

    /**
    * @brief Default constructor
    * @details This constructor initializes the TCPSendIdDTO with default values.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    TCPSendIdDTO();

    /**
    * @brief Destructor
    * @details Default destructor for TCPSendIdDTO.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    ~TCPSendIdDTO() override = default;

    /**
    * @brief Clone the DTO
    * @return A pointer to the cloned IDTO object
    * @details Creates a copy of the current TCPSendIdDTO object.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    IDTO *clone() override;

    /**
    * @brief Set the client ID
    * @param id The ID to set for the client
    * @details Sets the client ID for the TCPSendIdDTO object.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    void setID(int id);

    /**
    * @brief Get the client ID
    * @return The client ID
    * @details Retrieves the client ID from the TCPSendIdDTO object.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    [[nodiscard]] int getID() const;

    /**
    * @brief Serialize the DTO
    * @return A vector of characters representing the serialized data
    * @details Serializes the TCPSendIdDTO object into a vector of characters.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    std::vector<char> serialize() override;

    /**
    * @brief Deserialize the DTO
    * @param data A vector of characters representing the serialized data
    * @details Deserializes the data into the TCPSendIdDTO object.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    void deserialize(std::vector<char> &data) override;

private:
    int _client_id; ///< The ID of the client
};

#endif //TCPSENDID_HPP
