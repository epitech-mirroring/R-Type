/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AShip.hpp"
#include "EntityManager.hpp"

/**
 * @class Player
 * @brief Player class
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class Player final : public AShip {
public:
	/**
     * @brief The constructor of the Player class
     * @param entityId The id of the player
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    explicit Player(int entityId);

	/**
     * @brief The destructor of the Player class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    ~Player() override =  default;

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

	/**
     * @brief Set the score of the player
     * @param score The score of the player
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setScore(int score);

	/**
     * @brief Get the score of the player
     * @return The score of the player
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] int getScore() const;

	/**
     * @brief Add a score to the player
     * @param score The score to add
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void addScore(int score);

private:
	/**
	 * The score of the player
	 */
    int _score;
};

#endif //PLAYER_HPP
