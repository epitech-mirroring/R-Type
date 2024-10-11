/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStopShoot.cpp
*/

#include "PlayerStopShoot.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStopShoot::PlayerStopShoot(): APlayerDTO(-1)
{
}

PlayerStopShoot::PlayerStopShoot(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStopShoot::clone()
{
	return new PlayerStopShoot();
}

std::vector<char> PlayerStopShoot::serializePlayer()
{
	return {};
}

void PlayerStopShoot::deserializePlayer(std::vector<char> &data)
{
}
