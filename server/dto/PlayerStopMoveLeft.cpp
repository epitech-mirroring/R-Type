/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopMoveLeft.cpp
*/

#include "PlayerStopMoveLeft.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStopMoveLeft::PlayerStopMoveLeft(): APlayerDTO(-1)
{
}

PlayerStopMoveLeft::PlayerStopMoveLeft(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStopMoveLeft::clone()
{
	return new PlayerStopMoveLeft();
}

std::vector<char> PlayerStopMoveLeft::serializePlayer()
{
	return {};
}

void PlayerStopMoveLeft::deserializePlayer(std::vector<char> &data)
{
}
