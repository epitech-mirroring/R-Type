/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStartMoveUp.cpp
*/

#include "PlayerStartMoveUp.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStartMoveUp::PlayerStartMoveUp(): APlayerDTO(-1)
{
}

PlayerStartMoveUp::PlayerStartMoveUp(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStartMoveUp::clone()
{
	return new PlayerStartMoveUp();
}

std::vector<char> PlayerStartMoveUp::serializePlayer()
{
	return {};
}

void PlayerStartMoveUp::deserializePlayer(std::vector<char> &data)
{
}
