/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

EntityManager::EntityManager(): _idCounter(0)
{
}

void EntityManager::addEntity(IEntity *entity)
{
    this->_entities.insert(std::make_pair(entity->getId(), entity));
}

void EntityManager::addEntityToCreationBuffer(IEntity *entity)
{
    this->_entityCreationBuffer.insert(std::make_pair(entity->getId(), entity));
}

void EntityManager::addEntityToDeletionBuffer(IEntity *entity)
{
    this->_entityDeletionBuffer.insert(std::make_pair(entity->getId(), entity));
}

std::unordered_map<int, IEntity *> &EntityManager::getEntities()
{
    return this->_entities;
}

std::unordered_map<int, IEntity *> &EntityManager::getEntityCreationBuffer()
{
    return this->_entityCreationBuffer;
}

std::unordered_map<int, IEntity *> &EntityManager::getEntityDeletionBuffer()
{
    return this->_entityDeletionBuffer;
}

void EntityManager::deleteEntity(const int entityId)
{
    if (this->_entities.find(entityId) == this->_entities.end()) {
        return;
    }
    this->_entities.erase(entityId);
}

void EntityManager::deleteAllEntities()
{
    this->_entities.clear();
}

void EntityManager::deleteDeadEntities()
{
    for(auto it = this->_entities.begin(); it != this->_entities.end(); ) {
        if (it->second->getLife() <= 0) {
            it = this->_entities.erase(it);
        } else {
            ++it;
        }
    }
}

IEntity *EntityManager::getEntity(const int entityId)
{
    if (this->_entities.find(entityId) == this->_entities.end()) {
        return nullptr;
    }
    return this->_entities[entityId];
}

void EntityManager::updateEntities(const float deltaTime)
{
    for (const auto & [_, entity] : this->_entities) {
        entity->update(deltaTime, *this);
    }
}

void EntityManager::updateEntity(const int entityId, const float deltaTime)
{
    this->_entities[entityId]->update(deltaTime, *this);
}

void EntityManager::updateEntity(IEntity *entity, const float deltaTime)
{
    entity->update(deltaTime, *this);
}

int EntityManager::getNewId()
{
    return this->_idCounter++;
}
