/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IEntity.hpp
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

class EntityManager; // Forward declaration of EntityManager

/**
 * @class IEntity
 * @brief The interface for all entities
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class IEntity {
public:
	/**
     * @enum IEntity::EntityDirection
     * @brief All the possible directions for the entities
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	enum EntityDirection {
		UP,
    	UP_LEFT,
        UP_RIGHT,
		DOWN,
        DOWN_LEFT,
        DOWN_RIGHT,
        LEFT,
        RIGHT,
        NONE,
	};

	/**
     * @brief The destructor of the IEntity class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual ~IEntity() = default;

	/**
     * @brief The update function of the entity
     * This is meant to be runt by the parent object and update the entity every frame
     * @note This is a pure virtual function and must be implemented in the child class
     * @param elapsedTime The time elapsed since the last frame
     * @param entityManager The entity manager
	 * @version v0.1.0
	 * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void update(float elapsedTime, EntityManager &entityManager) = 0;

	/**
     * @brief The getter for the id of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The id of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] virtual int getId() const = 0;

	/**
     * @brief The getter for the x position of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The x position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual float getPosX() const = 0;

	/**
     * @brief The getter for the y position of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The y position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual float getPosY() const = 0;

	/**
     * @brief The getter for the speed of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The speed of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual float getSpeed() const = 0;

	/**
     * @brief The getter for the width of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The width of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual int getWidth() const = 0;

	/**
     * @brief The getter for the height of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The height of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual int getHeight() const = 0;

	/**
     * @brief The getter for the direction of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @return The direction of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] virtual IEntity::EntityDirection getDirection() const = 0;

	/**
     * @brief The setter for the id of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param id The id of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void setId(int id) = 0;

	/**
     * @brief The setter for the x position of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param posX The x position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual void setPosX(float posX) = 0;

	/**
     * @brief The setter for the y position of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param posY The y position of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    virtual void setPosY(float posY) = 0;

	/**
     * @brief The setter for the speed of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param speed The speed of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void setSpeed(float speed) = 0;

	/**
     * @brief The setter for the width of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param width The width of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void setWidth(int width) = 0;

	/**
     * @brief The setter for the height of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param height The height of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void setHeight(int height) = 0;

	/**
     * @brief The setter for the direction of the entity
     * @note This is a pure virtual function and must be implemented in the child class
     * @param direction The direction of the entity
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	virtual void setDirection(EntityDirection direction) = 0;
};

#endif //IENTITY_HPP
