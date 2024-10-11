/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTO.hpp
*/

#ifndef IDTO_HPP
#define IDTO_HPP

#include <vector>

/**
 * @class IDTO
 * @brief Interface for DTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class IDTO {
public:
	/**
     * @brief The destructor of the IDTO class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual ~IDTO() = default;

	/**
     * @brief Serialize the DTO to a vector of char (binary)
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The serialized DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual std::vector<char> serialize() = 0;

	/**
     * @brief Deserialize the DTO from a vector of char (binary)
     * @note This is a pure virtual function and must be implemented in the child class
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual void deserialize(std::vector<char> &data) = 0;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual IDTO *clone() = 0;
};

#endif //IDTO_HPP
