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
#include "../network/protocol/dto/player/PlayerActionEnum.hpp"

#include <iostream>

GameLogic::GameLogic(const float minDeltaTime) : _entityManager(new EntityManager()),
    _isRunning(false), _playerNb(0), _minDeltaTime(minDeltaTime),
    _currentTime(0), _runningTime(0), _spawnTime(2.0), _lastSpawnTime(0),
    _nbSpawned(0), _speedCoeff(1.0)
{
    this->_spawnThresholds = {
        {10, 1.5, 0.5},
        {15, 1.0, 0.5},
        {20, 0.5, 0.5},
        {25, 0.25, 0.25}
    };
}

GameLogic::~GameLogic()
{
    delete _entityManager;
}

void GameLogic::loop(float deltaTime)
{
    deltaTime = deltaTime * _speedCoeff;
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
    _lastSpawnTime = 0;
    _nbSpawned++;
}

void GameLogic::updateEntities()
{
    _entityManager->updateEntities(_currentTime);
    _currentTime = this->_currentTime - _minDeltaTime;
    this->handleDeadEntities();
    this->handleCollisions();
}

void GameLogic::speedUpSpawning()
{
    if (_spawnThresholds.empty()) {
        return;
    }
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
            if (entity->getEntityType() == PLAYER && otherEntity->getEntityType() == PLAYER) {
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

void GameLogic::handleDeadEntities() const
{
    std::unordered_map<int , IEntity *> const entities = _entityManager->getEntities();

    for (auto [entityId, entity] : entities)
    {
        if (entity->getLife() <= 0) {
            _entityManager->addEntityToDeletionBuffer(entity);
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

void GameLogic::deletePlayer(const int playerId)
{
    _entityManager->deleteEntity(playerId);
    _playerNb = std::max(0, _playerNb - 1);
    if (_playerNb <= 0) {
        _isRunning = false;
    }
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

void GameLogic::handlePlayerStart(const PlayerActionStartDTO* playerActionStartDTO) const
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

void GameLogic::handlePlayerStop(const PlayerActionStopDTO* playerActionStopDTO) const
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

void GameLogic::handleGameSpeed(const GameSpeedDTO *gameSpeedDTO)
{
    if (gameSpeedDTO->getSpeed() == SLOWER) {
        _speedCoeff = std::max(0.2f, _speedCoeff - 0.1f);
    } else if (gameSpeedDTO->getSpeed() == FASTER) {
        _speedCoeff = std::min(3.0f, _speedCoeff + 0.1f);
    }
}
