/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerActionStopDTO.cpp
*/

#include "PlayerActionStopDTO.hpp"

PlayerActionStopDTO::PlayerActionStopDTO(): APlayerDTO(-1)
{
}

PlayerActionStopDTO::PlayerActionStopDTO(const int entityId, const PlayerAction action)
	: APlayerDTO(entityId), _action(action) {}

IDTO *PlayerActionStopDTO::clone()
{
	return new PlayerActionStopDTO();
}

std::vector<char> PlayerActionStopDTO::serializePlayer()
{
	std::vector<char> data = BinaryConversion::convert<PlayerAction>(this->_action);
	return data;
}

void PlayerActionStopDTO::deserializePlayer(std::vector<char> &data)
{
	this->_action = BinaryConversion::consume<PlayerAction>(data);
}

void PlayerActionStopDTO::setAction(const PlayerAction action)
{
	this->_action = action;
}

PlayerAction PlayerActionStopDTO::getAction() const
{
	return this->_action;
}
