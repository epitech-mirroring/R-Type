/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** APlayerDTO.cpp
*/

#include "APlayerDTO.hpp"
#include "../utils/BinaryVector.hpp"

APlayerDTO::APlayerDTO (const int playerId) : _playerId(playerId)
{
}

std::vector<char> APlayerDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_playerId);
    data += this->serializePlayer();
    return data;
}

void APlayerDTO::deserialize(std::vector<char> &data)
{
    this->_playerId = BinaryConversion::consume<int>(data);

    this->deserializePlayer(data);
}

void APlayerDTO::setPlayerId(const int playerId)
{
    this->_playerId = playerId;
}

int APlayerDTO::getPlayerId() const
{
    return this->_playerId;
}
