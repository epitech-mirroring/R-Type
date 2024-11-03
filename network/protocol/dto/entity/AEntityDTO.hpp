/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntityDTO.hpp
*/

#ifndef AENTITYDTO_HPP
#define AENTITYDTO_HPP

#include "../IDTO.hpp"
#include "EntityTypeEnum.hpp"
#include "../../conversion/BinaryVector.hpp"

/**
 * @class AEntityDTO
 * @brief Class for Entity DTO
 * @inherit IDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AEntityDTO : public IDTO {
public:
	/**
     * @brief The destructor of the AEntityDTO class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~AEntityDTO() override = default;

	/**
	 * @brief Serialize the DTO to a vector of char (binary)
	 * @return The serialized entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
    std::vector<char> serialize() final;

	/**
	 * @brief Deserialize the DTO from a vector of char (binary)
	 * @param data The data to deserialize
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void deserialize(std::vector<char> &data) final;

	/**
	 * @brief Clone the DTO (create a new instance of the DTO)
	 * @return The cloned DTO
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	IDTO *clone() override = 0;

	/**
	 * @brief Set the id of the entity
	 * @param entityId The id of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	void setEntityId(int entityId);

	/**
	 * @brief Get the id of the entity
	 * @return The id of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	[[nodiscard]] int getEntityId() const;

	/**
     * @brief Set the type of the entity
     * @param entityType The type of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setEntityType(EntityType entityType);

	/**
     * @brief Get the type of the entity
     * @return The type of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] EntityType getEntityType() const;

protected:
	/**
	 * @brief The constructor of the AEntityDTO class
	 * @param entityId The id of the entity
	 * @param entityType The type of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	AEntityDTO(int entityId, EntityType entityType);

	/**
     * @brief Serialize the entity to a vector of char (binary)
     * @return The serialized entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual std::vector<char> serializeEntity() = 0;

	/**
     * @brief Deserialize the entity from a vector of char (binary)
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual void deserializeEntity(std::vector<char> &data) = 0;

	/**
     * @brief The id of the entity
     */
    int _entityId;

	/**
     * @brief The type of the entity
     */
    EntityType _entityType;
};

#endif //AENTITYDTO_HPP
