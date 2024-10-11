/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityDeletionDTO.hpp
*/

#ifndef ENTITYDELETIONDTO_HPP
#define ENTITYDELETIONDTO_HPP

#include "AEntityDTO.hpp"

/**
 * @class EntityDeletionDTO
 * @brief Class for Entity Deletion DTO
 * @inherit AEntityDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class EntityDeletionDTO final : public AEntityDTO {
public:
	/**
     * @brief The constructor of the EntityDeletionDTO class
     * @note This constructor is used for deserialization
     * (all the attributes are set to default values)
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	EntityDeletionDTO();

	/**
     * @brief The constructor of the EntityDeletionDTO class
     * @param entityId The id of the entity
     * @param entityType The type of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	EntityDeletionDTO(int entityId, IEntity::EntityType entityType);

	/**
     * @brief The destructor of the EntityDeletionDTO class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~EntityDeletionDTO() override = default;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	IDTO *clone() override;

	/**
     * @brief Serialize the DTO to a vector of char (binary)
     * @return The serialized entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	std::vector<char> serializeEntity() override;

	/**
     * @brief Deserialize the DTO from a vector of char (binary)
     * @note It will fill the attributes of the DTO with the data
     * @param data The data to deserialize
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void deserializeEntity(std::vector<char>& data) override;
};

#endif //ENTITYDELETIONDTO_HPP
