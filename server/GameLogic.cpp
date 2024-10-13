/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameLogic.cpp
*/

#include "GameLogic.hpp"
#include "entities/BasicEnemy.hpp"
#include "entities/Player.hpp"
#include "Random.hpp"
#include "dto/player/PlayerActionEnum.hpp"

#include <iostream>

GameLogic::GameLogic(const float minDeltaTime) : _entityManager(new EntityManager()), _isRunning(false), _playerNb(0), _minDeltaTime(minDeltaTime), _currentTime(0), _runningTime(0), _spawnTime(5), _lastSpawnTime(0), _nbSpawned(0)
{
    this->_spawnThresholds = {
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
    IEntity *enemy = new BasicEnemy(_entityManager->getNewId(), static_cast<float>(Random::getRandom() % 1080));
    _entityManager->addEntityToCreationBuffer(enemy);
    _lastSpawnTime = this->_lastSpawnTime - _spawnTime;
    _nbSpawned++;
}

void GameLogic::updateEntities()
{
    _entityManager->updateEntities(_currentTime);
    _currentTime = this->_currentTime - _minDeltaTime;
    this->handleCollisions();
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

void GameLogic::handleCollisions() const
{
    std::unordered_map<int , IEntity *> const entities = _entityManager->getEntities();

    for (auto [entityId, entity] : entities)
    {
        for (auto [otherEntityId, otherEntity] : entities)
        {
            if (entityId == otherEntityId) {
                continue;
            }
            if (entity->isColliding(otherEntity))
            {
                entity->onCollision(otherEntity);
                otherEntity->onCollision(entity);
                if (entity->getLife() <= 0) {
                    _entityManager->addEntityToDeletionBuffer(entity);
                }
                if (otherEntity->getLife() <= 0) {
                    _entityManager->addEntityToDeletionBuffer(otherEntity);
                }
            }
        }
    }
}

int GameLogic::createPlayer()
{
    IEntity *player = new Player(_entityManager->getNewId());
    _entityManager->addEntityToCreationBuffer(player);
    _playerNb++;
    if (_playerNb >= 1) {
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

void GameLogic::handlePlayerStart(PlayerActionStartDTO* playerActionStartDTO)
{
    auto *player = dynamic_cast<Player *> (_entityManager->getEntity(playerActionStartDTO->getPlayerId()));
    if (player == nullptr) {
        return;
    }
    if (playerActionStartDTO->getAction() == SHOOT) {
        player->setShooting(true);
        return;
    }
    if (playerActionStartDTO->getAction() == MOVE_UP) {
        player->addDirection(IEntity::EntityDirection::UP);
    } else if (playerActionStartDTO->getAction() == MOVE_DOWN) {
        player->addDirection(IEntity::EntityDirection::DOWN);
    } else if (playerActionStartDTO->getAction() == MOVE_LEFT) {
        player->addDirection(IEntity::EntityDirection::LEFT);
    } else if (playerActionStartDTO->getAction() == MOVE_RIGHT) {
        player->addDirection(IEntity::EntityDirection::RIGHT);
    }
}

void GameLogic::handlePlayerStop(PlayerActionStopDTO* playerActionStopDTO)
{
    auto *player = dynamic_cast<Player *> (_entityManager->getEntity(playerActionStopDTO->getPlayerId()));
    if (player == nullptr) {
        return;
    }
    if (playerActionStopDTO->getAction() == SHOOT) {
        player->setShooting(false);
        return;
    }
    if (playerActionStopDTO->getAction() == MOVE_UP) {
        player->removeDirection(IEntity::EntityDirection::UP);
    } else if (playerActionStopDTO->getAction() == MOVE_DOWN) {
        player->removeDirection(IEntity::EntityDirection::DOWN);
    } else if (playerActionStopDTO->getAction() == MOVE_LEFT) {
        player->removeDirection(IEntity::EntityDirection::LEFT);
    } else if (playerActionStopDTO->getAction() == MOVE_RIGHT) {
        player->removeDirection(IEntity::EntityDirection::RIGHT);
    }
}
