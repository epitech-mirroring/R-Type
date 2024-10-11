/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopMoveRight.cpp
*/

#include "PlayerStopMoveRight.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStopMoveRight::PlayerStopMoveRight(): APlayerDTO(-1)
{
}

PlayerStopMoveRight::PlayerStopMoveRight(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStopMoveRight::clone()
{
	return new PlayerStopMoveRight();
}

std::vector<char> PlayerStopMoveRight::serializePlayer()
{
	return {};
}

void PlayerStopMoveRight::deserializePlayer(std::vector<char> &data)
{
}
