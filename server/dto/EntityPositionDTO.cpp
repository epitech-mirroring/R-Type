/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityPositionDTO.cpp
*/

#include "EntityPositionDTO.hpp"
#include "../utils/BinaryVector.hpp"

EntityPositionDTO::EntityPositionDTO(): AEntityDTO(-1, IEntity::NO_TYPE), _posX(0), _posY(0)
{
}

EntityPositionDTO::EntityPositionDTO(const int entityId, const IEntity::EntityType entityType,
	const int posX, const int posY)
	: AEntityDTO(entityId, entityType), _posX(posX), _posY(posY)
{
}

IDTO *EntityPositionDTO::clone()
{
	return new EntityPositionDTO();
}

void EntityPositionDTO::setPosX(const int posX)
{
	this->_posX = posX;
}

int EntityPositionDTO::getPosX() const
{
	return this->_posX;
}

void EntityPositionDTO::setPosY(const int posY)
{
	this->_posY = posY;
}

int EntityPositionDTO::getPosY() const
{
	return this->_posY;
}

std::vector<char> EntityPositionDTO::serializeEntity()
{
	std::vector<char> data = BinaryConversion::convert<int>(this->_posX);
	data += BinaryConversion::convert<int>(this->_posY);
	return data;
}

void EntityPositionDTO::deserializeEntity(std::vector<char> &data)
{
	this->_posX = BinaryConversion::consume<int>(data);
	this->_posY = BinaryConversion::consume<int>(data);
}
