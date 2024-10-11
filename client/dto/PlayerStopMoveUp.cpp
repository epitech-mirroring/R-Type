/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopMoveUp.cpp
*/

#include "PlayerStopMoveUp.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStopMoveUp::PlayerStopMoveUp(): APlayerDTO(-1)
{
}

PlayerStopMoveUp::PlayerStopMoveUp(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStopMoveUp::clone()
{
	return new PlayerStopMoveUp();
}

std::vector<char> PlayerStopMoveUp::serializePlayer()
{
	return {};
}

void PlayerStopMoveUp::deserializePlayer(std::vector<char> &data)
{
}
