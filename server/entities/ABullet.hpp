/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ABullet.hpp
*/

#ifndef ABULLET_HPP
#define ABULLET_HPP

#include "AEntity.hpp"

/**
 * @class ABullet
 * @brief Abstract class for bullets
 * @inherit AEntity
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class ABullet : public AEntity {
public:
	/**
     * @brief The constructor of the ABullet class
     * @param entityId The id of the bullet
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	explicit ABullet(int entityId);

	/**
     * @brief The destructor of the ABullet class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~ABullet() override = default;

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
	void update(float elapsedTime, EntityManager &entityManager) override;
};

#endif //ABULLET_HPP
