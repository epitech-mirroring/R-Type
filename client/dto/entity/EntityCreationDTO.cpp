/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityCreationDTO.cpp
*/

#include "EntityCreationDTO.hpp"

EntityCreationDTO::EntityCreationDTO(): AEntityDTO(-1, NO_TYPE), _posX(0), _posY(0)
{
}

EntityCreationDTO::EntityCreationDTO(const int entityId, const EntityType entityType,
	const int posX, const int posY)
	: AEntityDTO(entityId, entityType), _posX(posX), _posY(posY)
{
}

IDTO *EntityCreationDTO::clone()
{
	return new EntityCreationDTO();
}

void EntityCreationDTO::setPosX(const int posX)
{
	this->_posX = posX;
}

int EntityCreationDTO::getPosX() const
{
	return this->_posX;
}

void EntityCreationDTO::setPosY(const int posY)
{
	this->_posY = posY;
}

int EntityCreationDTO::getPosY() const
{
	return this->_posY;
}

std::vector<char> EntityCreationDTO::serializeEntity()
{
	std::vector<char> data = BinaryConversion::convert<int>(this->_posX);
	data += BinaryConversion::convert<int>(this->_posY);
	return data;
}

void EntityCreationDTO::deserializeEntity(std::vector<char> &data)
{
	this->_posX = BinaryConversion::consume<int>(data);
	this->_posY = BinaryConversion::consume<int>(data);
}
