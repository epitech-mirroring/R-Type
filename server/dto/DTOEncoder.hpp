/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOEncoder.hpp
*/

#ifndef DTOENCODER_HPP
#define DTOENCODER_HPP

#include "IDTOEncoder.hpp"
#include "DTORegistry.hpp"
#include "DTOException.hpp"

/**
 * @class DTOEncoder
 * @brief Class for DTO encoder
 * @inherit IDTOEncoder
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class DTOEncoder final : public IDTOEncoder {
public:
	/**
     * @brief The constructor of the DTOEncoder class
     * @note The DTORegistry is set to nullptr by default
     * (it must be set before encoding a DTO)
     * @param dtoRegistry The DTO registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	explicit DTOEncoder(DTORegistry *dtoRegistry = nullptr);

	/**
     * @brief The destructor of the DTOEncoder class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~DTOEncoder() override = default;

	/**
     * @brief Encode the DTO to a vector of char (binary)
     * @param dto The DTO to encode
	 * @return The encoded DTO
	 * @throw DTOException If the DTORegistry is not set or
	 * if the DTO is not found in the registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] std::vector<char> encode(IDTO &dto) const override;

	/**
     * @brief Get the DTO registry
     * @return The DTO registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] DTORegistry &getDTORegistry() const;

	/**
     * @brief Set the DTO registry
     * @param dtoRegistry The DTO registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setDTORegistry(DTORegistry *dtoRegistry);

private:
	/**
     * @brief The DTO registry
     */
	DTORegistry *_dtoRegistry;

};

#endif //DTOENCODER_HPP
