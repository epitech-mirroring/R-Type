/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTOEncoder.hpp
*/

#ifndef IDTOENCODER_HPP
#define IDTOENCODER_HPP

#include "IDTO.hpp"
#include <vector>

/**
 * @class IDTOEncoder
 * @brief Interface for DTO Encoder
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class IDTOEncoder {
public:
	/**
     * @brief The destructor of the IDTOEncoder class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual ~IDTOEncoder() = default;

	/**
     * @brief Encode the DTO to a vector of char (binary)
     * @note This is a pure virtual function and must be implemented in the child class
     * @param dto The DTO to encode
     * @return The encoded DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual std::vector<char> encode(IDTO &dto) const = 0;
};

#endif //IDTOENCODER_HPP
