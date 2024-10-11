/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStartMoveRight.cpp
*/

#include "PlayerStartMoveRight.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStartMoveRight::PlayerStartMoveRight(): APlayerDTO(-1)
{
}

PlayerStartMoveRight::PlayerStartMoveRight(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStartMoveRight::clone()
{
	return new PlayerStartMoveRight();
}

std::vector<char> PlayerStartMoveRight::serializePlayer()
{
	return {};
}

void PlayerStartMoveRight::deserializePlayer(std::vector<char> &data)
{
}
