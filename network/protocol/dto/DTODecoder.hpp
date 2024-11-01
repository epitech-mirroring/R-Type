/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTODecoder.hpp
*/

#ifndef DTODECODER_HPP
#define DTODECODER_HPP

#include "IDTODecoder.hpp"
#include "DTORegistry.hpp"
#include "DTOException.hpp"

/**
 * @class DTODecoder
 * @brief Class for DTO decoder
 * @inherit IDTODecoder
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class DTODecoder final: public IDTODecoder {
public:
	/**
     * @brief The constructor of the DTODecoder class
	 * @note The DTORegistry is set to nullptr by default
	 * (it must be set before encoding a DTO)
     * @param dtoRegistry The DTO registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	explicit DTODecoder(DTORegistry *dtoRegistry = nullptr);

	/**
     * @brief The destructor of the DTODecoder class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~DTODecoder() override = default;

	/**
     * @brief Decode the data to a DTO
     * @param data The data to decode
     * @return The decoded DTO
     * @throw DTOException If the DTORegistry is not set or
     * if the DTO is not found in the registry
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	IDTO *decode(std::vector<char> &data) const override;

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

#endif //DTODECODER_HPP
