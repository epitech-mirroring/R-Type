/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityDeletionDTO.cpp
*/

#include "EntityDeletionDTO.hpp"
#include "../utils/BinaryVector.hpp"


EntityDeletionDTO::EntityDeletionDTO(): AEntityDTO(-1, NO_TYPE)
{
}

EntityDeletionDTO::EntityDeletionDTO(const int entityId, const EntityType entityType)
	: AEntityDTO(entityId, entityType)
{
}

IDTO *EntityDeletionDTO::clone()
{
	return new EntityDeletionDTO();
}

std::vector<char> EntityDeletionDTO::serializeEntity()
{
	return {};
}

void EntityDeletionDTO::deserializeEntity(std::vector<char> &data)
{
}
