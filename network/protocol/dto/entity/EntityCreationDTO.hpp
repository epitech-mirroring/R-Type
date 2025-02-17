/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityCreationDTO.hpp
*/

#ifndef ENTITYCREATIONDTO_HPP
#define ENTITYCREATIONDTO_HPP

#include "AEntityDTO.hpp"

/**
 * @class EntityCreationDTO
 * @brief Class for Entity Creation DTO
 * @inherit AEntityDTO
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class EntityCreationDTO final: public AEntityDTO {
public:
	/**
	 * @brief The constructor of the EntityCreationDTO class
	 * @note This constructor is used for deserialization
	 * (all the attributes are set to default values)
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	EntityCreationDTO();

	/**
	 * @brief The constructor of the EntityCreationDTO class
	 * @param entityId The id of the entity
	 * @param entityType The type of the entity
	 * @param posX The x position of the entity
	 * @param posY The y position of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	EntityCreationDTO(int entityId, EntityType entityType, int posX, int posY);

	/**
     * @brief The destructor of the EntityCreationDTO class
     * @version v0.1.0
     * @since v0.1.0
	 * @author Marius PAIN
     */
	~EntityCreationDTO() override = default;

	/**
     * @brief Clone the DTO (create a new instance of the DTO)
     * @return The cloned DTO
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	IDTO *clone() override;

	/**
     * @brief Set the x position of the entity
     * @param posX The x position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setPosX(int posX);

	/**
     * @brief Get the x position of the entity
     * @return The x position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] int getPosX() const;

	/**
     * @brief Set the y position of the entity
     * @param posY The y position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setPosY(int posY);

	/**
     * @brief Get the y position of the entity
     * @return The y position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] int getPosY() const;

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

private:
	/**
     * @brief The x position of the entity
     */
	int _posX;

	/**
     * @brief The y position of the entity
     */
	int _posY;
};

#endif //ENTITYCREATIONDTO_HPP
