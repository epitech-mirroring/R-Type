/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityManager.hpp
*/

#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <unordered_map>

#include "IEntity.hpp"

/**
 * @class EntityManager
 * @brief Class that manages all entities
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius Pain
 */
class EntityManager {
public:
	/**
     * @brief The constructor of the EntityManager class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	EntityManager();

	/**
     * @brief The destructor of the EntityManager class
     * @note This destructor is default
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~EntityManager() = default;

	/**
     * @brief Add an entity to the entity manager
     * @param entity The entity to add
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void addEntity(IEntity *entity);

	/**
     * @brief Get all the entities
     * @return The entities (unordered map of int and IEntity *)
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	std::unordered_map<int, IEntity *> &getEntities();

	/**
     * @brief Delete an entity
     * @param entityId The id of the entity to delete
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void deleteEntity(int entityId);

	/**
     * @brief Delete all entities in the entity manager
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void deleteAllEntities();

	/**
     * @brief Delete all dead entities in the entity manager
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void deleteDeadEntities();

	/**
     * @brief Get an entity by its id
     * @param entityId The id of the entity to get
     * @return The entity (IEntity *)
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    IEntity *getEntity(int entityId);

	/**
     * @brief Update all entities
     * @param deltaTime The time elapsed since the last frame
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void updateEntities(float deltaTime);

	/**
     * @brief Update an entity by its id
     * @param entityId The id of the entity to update
     * @param deltaTime The time elapsed since the last frame
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void updateEntity(int entityId, float deltaTime);

	/**
     * @brief Update an entity
     * @param entity The entity to update
     * @param deltaTime The time elapsed since the last frame
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void updateEntity(IEntity *entity, float deltaTime);

	/**
     * @brief Get a new id for an entity
     * @return The new id
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	int getNewId();

private:
	/**
     * @brief Map of all entities present in the entity manager
     */
	std::unordered_map<int, IEntity *> _entities;

	/**
     * @brief The id counter
     */
	int _idCounter;
};

#endif //ENTITYMANAGER_HPP
