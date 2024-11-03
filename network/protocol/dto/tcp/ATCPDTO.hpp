/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#ifndef ATCPDTO_HPP
#define ATCPDTO_HPP

#include "../IDTO.hpp"
#include "../../conversion/BinaryVector.hpp"
#include "MessageTypeEnum.hpp"

/**
 * @class ATCPDTO
 * @brief Represents a TCP DTO
 * @details This class is the base class for all TCP DTOs
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class ATCPDTO : public IDTO {
public:
    /**
    * @brief Default destructor
    * @details This destructor cleans up the ATCPDTO object
    * @version 0.1.0
    * @since 0.1.0
    * @author Simon GANIER-LOMBARD
    */
    ~ATCPDTO() override = default;

    /**
    * @brief Serializes the DTO to a vector of chars
    * @return A vector of chars representing the serialized DTO
    * @version 0.1.0
    * @since 0.1.0
    */
    std::vector<char> serialize() override;

    /**
    * @brief Deserializes the DTO from a vector of chars
    * @param data A vector of chars representing the serialized DTO
    * @version 0.1.0
    * @since 0.1.0
    */
    void deserialize(std::vector<char> &data) override;

    /**
    * @brief Clones the DTO
    * @return A pointer to the cloned DTO
    * @version 0.1.0
    * @since 0.1.0
    */
    IDTO *clone() override = 0;

    /**
    * @brief Sets the client ID
    * @param client_id The client ID to set
    * @version 0.1.0
    * @since 0.1.0
    */
    void setClientId(int client_id);

    /**
    * @brief Gets the client ID
    * @return The client ID
    * @version 0.1.0
    * @since 0.1.0
    */
    [[nodiscard]] int getClientId() const;

protected:
    /**
    * @brief Serializes the TCP-specific part of the DTO
    * @return A vector of chars representing the serialized TCP-specific part of the DTO
    * @version 0.1.0
    * @since 0.1.0
    */
    virtual std::vector<char> serializeTCP() = 0;

    /**
    * @brief Deserializes the TCP-specific part of the DTO from a vector of chars
    * @param data A vector of chars representing the serialized TCP-specific part of the DTO
    * @version 0.1.0
    * @since 0.1.0
    */
    virtual void deserializeTCP(std::vector<char> &data) = 0;

    /**
    * @brief Constructor with client ID
    * @param client_id The client ID to set
    * @version 0.1.0
    * @since 0.1.0
    */
    ATCPDTO(int client_id);

    int _client_id; ///< The client ID
};

#endif //ATCPDTO_HPP
