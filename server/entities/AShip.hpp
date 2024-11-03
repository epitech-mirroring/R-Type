/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AShip.hpp
*/

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AEntity.hpp"

/**
 * @class AShip
 * @brief Abstract class for all ships (The ship are entities that can shoot)
 * @inherit AEntity
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class AShip : public AEntity {
public:
	/**
     * @brief The destructor of the AShip class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	~AShip() override = default;

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
	void update(float elapsedTime, EntityManager &entityManager) override = 0;

	/**
     * @brief Set if the ship is shooting
     * @param isShooting If the ship is shooting
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setShooting(bool isShooting);

	/**
     * @brief Set the shoot cooldown of the ship
     * @param shootCooldown The shoot cooldown of the ship
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setShootCooldown(float shootCooldown);

	/**
     * @brief Set the current shoot cooldown of the ship
     * @param currentShootCooldown The current shoot cooldown of the ship
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void setCurrentShootCooldown(float currentShootCooldown);

	/**
     * @brief Get if the ship is shooting
     * @return If the ship is shooting
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] bool isShooting() const;

	/**
     * @brief Get the shoot cooldown of the ship
     * @return The shoot cooldown of the ship
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] float getShootCooldown() const;

	/**
     * @brief Get the current shoot cooldown of the ship
     * @return The current shoot cooldown of the ship
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	[[nodiscard]] float getCurrentShootCooldown() const;

	/**
     * @brief Remove life from the ship
     * @param life The life to remove from the ship
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
	void removeLife(int life);

protected:
	/**
	 * @brief The constructor of the AShip class
	 * @note This is a protected constructor and can only be called by the child class
	 * @param entityId The id of the entity
	 * @version v0.1.0
	 * @since v0.1.0
	 * @author Marius PAIN
	 */
	explicit AShip(int entityId);

	/**
     * @brief If the ship is shooting
     */
	bool _isShooting;

	/**
     * @brief The shoot cooldown of the ship
     */
	float _shootCooldown;

	/**
     * @brief The current shoot cooldown of the ship
     */
	float _currentShootCooldown;
};

#endif //ASHIP_HPP
