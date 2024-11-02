/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTODecoder.hpp
*/

#ifndef IDTODECODER_HPP
#define IDTODECODER_HPP

#include <vector>
#include "IDTO.hpp"

/**
 * @class IDTODecoder
 * @brief Interface for DTO Decoder
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class IDTODecoder {
public:
	/**
     * @brief The destructor of the IDTODecoder class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual ~IDTODecoder() = default;

	/**
     * @brief Decode the DTO from a vector of char (binary)
     * @note This is a pure virtual function and must be implemented in the child class
     * @param data The data to decode
     * @return The decoded DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual IDTO *decode(std::vector<char> &data) const = 0;
};

#endif //IDTODECODER_HPP
