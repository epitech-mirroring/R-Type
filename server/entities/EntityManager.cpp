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
    if (this->_entities.find(entity->getId()) != this->_entities.end())

    this->_entities.insert(std::make_pair(entity->getId(), entity));
}

std::unordered_map<int, IEntity *> &EntityManager::getEntities()
{
    return this->_entities;
}

void EntityManager::deleteEntity(const int entityId)
{
    this->_entities.erase(entityId);
}

void EntityManager::deleteAllEntities()
{
    this->_entities.clear();
}

IEntity *EntityManager::getEntity(const int entityId)
{
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
