/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTORegistry.hpp
*/

#ifndef DTOREGISTRY_HPP
#define DTOREGISTRY_HPP

#include "IDTO.hpp"
#include <vector>

/**
 * @class DTORegistry
 * @brief Class for DTO Registry
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class DTORegistry {
public:
	/**
     * @brief The constructor of the DTORegistry class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	DTORegistry();

	/**
     * @brief The destructor of the DTORegistry class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~DTORegistry();

	/**
     * @brief Get the magic number of the DTO (index in the vector)
     * @param dto The DTO to get the magic number
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	int getDTOId(const IDTO *dto) const;

	/**
     * @brief Get the DTO by its magic number
     * @param dtoID The magic number of the DTO
     * @return The DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] IDTO *getDTOById(int dtoID) const;

private:
	/**
     * @brief The vector of DTO
     */
	std::vector<IDTO *> _dtos;
};

#endif //DTOREGISTRY_HPP
