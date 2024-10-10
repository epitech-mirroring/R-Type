/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameLogic.hpp
*/

#ifndef GAMELOGIC_HPP
#define GAMELOGIC_HPP

#include "entities/EntityManager.hpp"
#include <vector>

class GameLogic {
public:
    explicit GameLogic(float minDeltaTime);
    ~GameLogic();
    void loop(float deltaTime);

    void spawnEnemy();
    void updateEntities();
    void speedUpSpawning();
    void checkCollisions();

    [[nodiscard]] int createPlayer();

    [[nodiscard]] EntityManager *getEntityManager() const;
    void setEntityManager(EntityManager *entityManager);
    [[nodiscard]] bool isRunning() const;
    void setIsRunning(bool isRunning);
    [[nodiscard]] float getMinDeltaTime() const;
    void setMinDeltaTime(float minDeltaTime);
    [[nodiscard]] float getCurrentTime() const;
    void setCurrentTime(float currentTime);
    [[nodiscard]] float getRunningTime() const;
    void setRunningTime(float runningTime);

private:
    EntityManager *_entityManager;
    bool _isRunning;
    int _playerNb;
    float _minDeltaTime;
    float _currentTime;
    float _runningTime;
    float _spawnTime;
    float _lastSpawnTime;
    int _nbSpawned;

    struct SpawnThreshold {
        int spawnCount;
        float minSpawnTime;
        float reduction;
    };
    std::vector<SpawnThreshold> _spawnThresholds;
};

#endif //GAMELOGIC_HPP
