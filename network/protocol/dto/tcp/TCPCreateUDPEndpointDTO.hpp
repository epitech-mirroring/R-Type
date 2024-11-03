/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/


#ifndef TCPCREATEUDPENDPOINT_HPP
#define TCPCREATEUDPENDPOINT_HPP

#include <asio/ip/udp.hpp>
#include "ATCPDTO.hpp"

/**
 * @brief Data Transfer Object for creating a UDP endpoint via TCP.
 * @details This class is used to create a UDP endpoint using TCP communication.
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class TCPCreateUDPEndpointDTO: public IDTO {
public:
    /**
    * @brief Default constructor.
    * @details Initializes the object without setting an endpoint.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    TCPCreateUDPEndpointDTO();

    /**
    * @brief Constructor with endpoint.
    * @details Initializes the object with a given UDP endpoint.
    * @param endpoint The UDP endpoint to initialize with.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    TCPCreateUDPEndpointDTO(asio::ip::udp::endpoint endpoint);

    /**
    * @brief Destructor.
    * @details Default destructor.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    ~TCPCreateUDPEndpointDTO() override = default;

    /**
    * @brief Clone the DTO.
    * @details Creates a copy of the current DTO object.
    * @return A pointer to the cloned DTO object.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    IDTO *clone() override;

    /**
    * @brief Set the UDP endpoint.
    * @details Sets the UDP endpoint for this DTO.
    * @param endpoint The UDP endpoint to set.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    void setEndpoint(asio::ip::udp::endpoint endpoint);

    /**
    * @brief Get the UDP endpoint.
    * @details Retrieves the UDP endpoint from this DTO.
    * @return The UDP endpoint.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    [[nodiscard]] asio::ip::udp::endpoint getEndpoint() const;

    /**
    * @brief Deserialize data.
    * @details Deserializes data from a vector of characters to populate the DTO.
    * @param data The data to deserialize.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    void deserialize(std::vector<char> &data) override;

    /**
    * @brief Serialize the DTO.
    * @details Serializes the DTO into a vector of characters.
    * @return A vector of characters representing the serialized DTO.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    std::vector<char> serialize() override;

private:
    /**
    * @brief The UDP endpoint.
    * @details Stores the UDP endpoint for this DTO.
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    asio::ip::udp::endpoint _endpoint;
};

#endif //TCPCREATEUDPENDPOINT_HPP
