/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityManager.cpp
*/

#include "EntityManager.hpp"

void EntityManager::addEntity(IEntity *entity)
{
    this->_entities.insert(std::make_pair(entity->getId(), entity));
}

std::unordered_map<int, IEntity *> &EntityManager::getEntities()
{
    return this->_entities;
}

void EntityManager::deleteEntity(const int id)
{
    this->_entities.erase(id);
}

void EntityManager::deleteAllEntities()
{
    this->_entities.clear();
}

IEntity *EntityManager::getEntity(const int id)
{
    return this->_entities[id];
}

void EntityManager::updateEntities(const float deltaTime)
{
    for (const auto & [_, entity] : this->_entities) {
        entity->update(deltaTime, *this);
    }
}

void EntityManager::updateEntity(const int id, const float deltaTime)
{
    this->_entities[id]->update(deltaTime, *this);
}

void EntityManager::updateEntity(IEntity *entity, const float deltaTime)
{
    entity->update(deltaTime, *this);
}

int EntityManager::getNewId()
{
    return this->_idCounter++;
}
