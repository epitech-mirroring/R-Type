/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopMoveDown.cpp
*/

#include "PlayerStopMoveDown.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStopMoveDown::PlayerStopMoveDown(): APlayerDTO(-1)
{
}

PlayerStopMoveDown::PlayerStopMoveDown(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStopMoveDown::clone()
{
	return new PlayerStopMoveDown();
}

std::vector<char> PlayerStopMoveDown::serializePlayer()
{
	return {};
}

void PlayerStopMoveDown::deserializePlayer(std::vector<char> &data)
{
}
