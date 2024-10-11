/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntityDTO.cpp
*/

#include "AEntityDTO.hpp"
#include "../utils/BinaryVector.hpp"

AEntityDTO::AEntityDTO (const int entityId, const IEntity::EntityType entityType) : _entityId(entityId), _entityType(entityType)
{
}

std::vector<char> AEntityDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_entityId);
    data += BinaryConversion::convert<IEntity::EntityType>(this->_entityType);
    data += this->serializeEntity();
    return data;
}

void AEntityDTO::deserialize(std::vector<char> &data)
{
    this->_entityId = BinaryConversion::consume<int>(data);
    this->_entityType = BinaryConversion::consume<IEntity::EntityType>(data);

    this->deserializeEntity(data);
}

void AEntityDTO::setEntityId(const int entityId)
{
    this->_entityId = entityId;
}

int AEntityDTO::getEntityId() const
{
    return this->_entityId;
}

void AEntityDTO::setEntityType(const IEntity::EntityType entityType)
{
    this->_entityType = entityType;
}

IEntity::EntityType AEntityDTO::getEntityType() const
{
    return this->_entityType;
}
