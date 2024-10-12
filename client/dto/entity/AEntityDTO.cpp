/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntityDTO.cpp
*/

#include "AEntityDTO.hpp"

AEntityDTO::AEntityDTO (const int entityId, const EntityType entityType) : _entityId(entityId), _entityType(entityType)
{
}

std::vector<char> AEntityDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_entityId);
    data += BinaryConversion::convert<EntityType>(this->_entityType);
    data += this->serializeEntity();
    return data;
}

void AEntityDTO::deserialize(std::vector<char> &data)
{
    this->_entityId = BinaryConversion::consume<int>(data);
    this->_entityType = BinaryConversion::consume<EntityType>(data);

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

void AEntityDTO::setEntityType(const EntityType entityType)
{
    this->_entityType = entityType;
}

EntityType AEntityDTO::getEntityType() const
{
    return this->_entityType;
}
