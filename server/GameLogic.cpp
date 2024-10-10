/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameLogic.cpp
*/

#include "GameLogic.hpp"
#include "entities/BasicEnemy.hpp"
#include "entities/Player.hpp"
#include <random>

GameLogic::GameLogic(const float minDeltaTime) : _entityManager(new EntityManager()), _isRunning(false), _playerNb(0), _minDeltaTime(minDeltaTime), _currentTime(0), _runningTime(0), _spawnTime(5), _lastSpawnTime(0), _nbSpawned(0)
{
    this->_spawnThresholds = {
        {30, 0.05, 0.05},
        {20, 0.1,  0.1},
        {10, 0.5,  0.1},
        {5,  1.0,  0.1},
        {0,  2.0,  1.0}
    };
}

GameLogic::~GameLogic()
{
    delete _entityManager;
}

void GameLogic::loop(const float deltaTime)
{
    if (!_isRunning) {
        return;
    }
    _currentTime += deltaTime;
    _runningTime += deltaTime;
    _lastSpawnTime += deltaTime;
    if (_currentTime >= _minDeltaTime) {
        this->updateEntities();
    }
    if (_lastSpawnTime >= _spawnTime) {
        this->spawnEnemy();
    }
    this->speedUpSpawning();
}

void GameLogic::spawnEnemy()
{
    IEntity *enemy = new BasicEnemy(_entityManager->getNewId(), static_cast<float>(random() % 1080));
    _entityManager->addEntity(enemy);
    _lastSpawnTime = 0;
    _nbSpawned++;
}

void GameLogic::updateEntities()
{
    _entityManager->updateEntities(_currentTime);
    _currentTime = 0;
}

void GameLogic::speedUpSpawning()
{
    for (const auto& [spawnCount, minSpawnTime, reduction] : _spawnThresholds) {
        if (_nbSpawned >= spawnCount && _spawnTime > minSpawnTime) {
            _spawnTime -= reduction;
            _nbSpawned = 0;
            break;
        }
    }
}

void GameLogic::checkCollisions()
{
    // TODO: Implement collision detection
}

int GameLogic::createPlayer()
{
    IEntity *player = new Player(_entityManager->getNewId());
    _entityManager->addEntity(player);
    _playerNb++;
    if (_playerNb > 1) {
        _isRunning = true;
    }
    return player->getId();
}

/**
 * GETTERS & SETTERS
 */

EntityManager *GameLogic::getEntityManager() const
{
    return _entityManager;
}

void GameLogic::setEntityManager(EntityManager *entityManager)
{
    _entityManager = entityManager;
}

bool GameLogic::isRunning() const
{
    return _isRunning;
}

void GameLogic::setIsRunning(const bool isRunning)
{
    _isRunning = isRunning;
}

float GameLogic::getMinDeltaTime() const
{
    return _minDeltaTime;
}

void GameLogic::setMinDeltaTime(const float minDeltaTime)
{
    _minDeltaTime = minDeltaTime;
}

float GameLogic::getCurrentTime() const
{
    return _currentTime;
}

void GameLogic::setCurrentTime(const float currentTime)
{
    _currentTime = currentTime;
}

float GameLogic::getRunningTime() const
{
    return _runningTime;
}

void GameLogic::setRunningTime(const float runningTime)
{
    _runningTime = runningTime;
}
