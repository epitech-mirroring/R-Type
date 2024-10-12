/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStartMoveLeft.cpp
*/

#include "PlayerStartMoveLeft.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStartMoveLeft::PlayerStartMoveLeft(): APlayerDTO(-1)
{
}

PlayerStartMoveLeft::PlayerStartMoveLeft(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStartMoveLeft::clone()
{
	return new PlayerStartMoveLeft();
}

std::vector<char> PlayerStartMoveLeft::serializePlayer()
{
	return {};
}

void PlayerStartMoveLeft::deserializePlayer(std::vector<char> &data)
{
}
