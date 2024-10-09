/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** BasicEnemy.hpp
*/

#ifndef BASICENEMY_HPP
#define BASICENEMY_HPP

#include "AShip.hpp"
#include "EntityManager.hpp"

/**
 * @class BasicEnemy
 * @brief Basic enemy class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class BasicEnemy final : public AShip {
public:

	/**
     * @brief The constructor of the BasicEnemy class
     * @param entityId The id of the enemy
     * @param posY The y position of the enemy
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	explicit BasicEnemy(int entityId, float posY);

	/**
     * @brief The destructor of the BasicEnemy class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~BasicEnemy() override = default;

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
	void update(float elapsedTime, EntityManager& entityManager) override;
};

#endif //BASICENEMY_HPP
