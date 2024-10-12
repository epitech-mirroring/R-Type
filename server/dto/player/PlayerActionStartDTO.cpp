/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerActionStartDTO.cpp
*/

#include "PlayerActionStartDTO.hpp"
#include "../utils/BinaryVector.hpp"


PlayerActionStartDTO::PlayerActionStartDTO(): APlayerDTO(-1)
{
}

PlayerActionStartDTO::PlayerActionStartDTO(const int entityId, const PlayerAction action)
	: APlayerDTO(entityId), _action(action) {}

IDTO *PlayerActionStartDTO::clone()
{
	return new PlayerActionStartDTO();
}

std::vector<char> PlayerActionStartDTO::serializePlayer()
{
	std::vector<char> data = BinaryConversion::convert<PlayerAction>(this->_action);
	return data;
}

void PlayerActionStartDTO::deserializePlayer(std::vector<char> &data)
{
	this->_action = BinaryConversion::consume<PlayerAction>(data);
}

void PlayerActionStartDTO::setAction(const PlayerAction action)
{
	this->_action = action;
}

PlayerAction PlayerActionStartDTO::getAction() const
{
	return this->_action;
}
