/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStartMoveDown.cpp
*/

#include "PlayerStartMoveDown.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStartMoveDown::PlayerStartMoveDown(): APlayerDTO(-1)
{
}

PlayerStartMoveDown::PlayerStartMoveDown(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStartMoveDown::clone()
{
	return new PlayerStartMoveDown();
}

std::vector<char> PlayerStartMoveDown::serializePlayer()
{
	return {};
}

void PlayerStartMoveDown::deserializePlayer(std::vector<char> &data)
{
}
