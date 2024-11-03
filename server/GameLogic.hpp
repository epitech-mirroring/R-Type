/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameLogic.hpp
*/

#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "entities/EntityManager.hpp"
#include "../network/protocol/dto/player/PlayerActionStartDTO.hpp"
#include "../network/protocol/dto/player/PlayerActionStopDTO.hpp"
#include <vector>

/**
 * @class GameLogic
 * @brief Class that manages the game logic
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class GameLogic {
public:
    /**
     * @brief The constructor of the GameLogic class
     * @param minDeltaTime The minimum delta time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    explicit GameLogic(float minDeltaTime);

	/**
     * @brief The destructor of the GameLogic class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    ~GameLogic();

	/**
     * @brief The loop function of the game logic
     * This is meant to be runt by the parent object and update the game logic every frame
     * @param deltaTime The time elapsed since the last frame
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void loop(float deltaTime);

	/**
     * @brief The spawn enemy function
     * It spawns an enemy
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void spawnEnemy();

	/**
     * @brief The update entities function
     * It updates all the entities
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void updateEntities();

	/**
     * @brief The speed-up spawning function
     * It speeds up the spawning of the enemies
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void speedUpSpawning();

    /**
     * @brief The handle collisions function
     * It checks the collisions between the entities and handle them
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void handleCollisions() const;

    /**
     * @brief The handle dead entities function
     * It checks the dead entities and handle them
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void handleDeadEntities() const;

    /**
     * @brief The create player function
     * It creates a player
     * @return The id of the player
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
     [[nodiscard]] int createPlayer();

    /**
     * @brief The delete player function
     * It deletes a player
     * @param playerId The id of the player to delete
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void deletePlayer(int playerId);

    /**
     * @brief The getter for the entity manager
     * @return The entity manager
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] EntityManager *getEntityManager() const;

    /**
     * @brief The setter for the entity manager
     * @param entityManager The entity manager
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setEntityManager(EntityManager *entityManager);

    /**
     * @brief The getter for the running state
     * @return The running state
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] bool isRunning() const;

    /**
     * @brief The setter for the running state
     * @param isRunning The running state
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setIsRunning(bool isRunning);

    /**
     * @brief The getter for the minimum delta time
     * @return The minimum delta time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getMinDeltaTime() const;

    /**
     * @brief The setter for the minimum delta time
     * @param minDeltaTime The minimum delta time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setMinDeltaTime(float minDeltaTime);

    /**
     * @brief The getter for the current time
     * @return The current time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getCurrentTime() const;

    /**
     * @brief The setter for the current time
     * @param currentTime The current time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setCurrentTime(float currentTime);

    /**
     * @brief The getter for the running time
     * @return The running time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    [[nodiscard]] float getRunningTime() const;

    /**
     * @brief The setter for the running time
     * @param runningTime The running time
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    void setRunningTime(float runningTime);

    void handlePlayerStart(const PlayerActionStartDTO *playerActionStartDTO) const;

    void handlePlayerStop(const PlayerActionStopDTO *playerActionStopDTO) const;

private:
    /**
     * @brief The entity manager (it manages the entities)
     */
    EntityManager *_entityManager;

    /**
     * @brief The running state
     */
    bool _isRunning;

    /**
     * @brief The number of players
     */
    int _playerNb;

    /**
     * @brief The minimum delta time (in seconds)
     */
    float _minDeltaTime;

    /**
     * @brief The current time (time in second since the game started)
     */
    float _currentTime;

    /**
     * @brief The running time (time in second since the game started)
     */
    float _runningTime;

    /**
     * @brief The spawn time (time in second between two spawns)
     */
    float _spawnTime;

    /**
     * @brief The last spawn time (time in second since the last spawn)
     */
    float _lastSpawnTime;

    /**
     * @brief The number of spawned enemies
     */
    int _nbSpawned;

    /**
     * @brief The spawn thresholds
     * It contains the spawn count, the minimum spawn time and the reduction
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    struct SpawnThreshold {
        /**
         * @brief The spawn count
         */
        int spawnCount;

        /**
         * @brief The minimum spawn time
         */
        float minSpawnTime;

        /**
         * @brief The reduction (in seconds)
         */
        float reduction;
    };

    /**
     * @brief The spawn thresholds (vector of SpawnThreshold)
     */
    std::vector<SpawnThreshold> _spawnThresholds;
};

#endif //GAMELOGIC_HPP
