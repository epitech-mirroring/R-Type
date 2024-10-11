/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerStartShoot.cpp
*/

#include "PlayerStartShoot.hpp"
#include "../utils/BinaryVector.hpp"


PlayerStartShoot::PlayerStartShoot(): APlayerDTO(-1)
{
}

PlayerStartShoot::PlayerStartShoot(const int playerId)
	: APlayerDTO(playerId)
{
}

IDTO *PlayerStartShoot::clone()
{
	return new PlayerStartShoot();
}

std::vector<char> PlayerStartShoot::serializePlayer()
{
	return {};
}

void PlayerStartShoot::deserializePlayer(std::vector<char> &data)
{
}
