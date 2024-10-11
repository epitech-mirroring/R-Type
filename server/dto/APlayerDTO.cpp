/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** APlayerDTO.cpp
*/

#include "APlayerDTO.hpp"
#include "../utils/BinaryVector.hpp"

APlayerDTO::APlayerDTO (const int PlayerId) : _PlayerId(PlayerId)
{
}

std::vector<char> APlayerDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_PlayerId);
    data += this->serializePlayer();
    return data;
}

void APlayerDTO::deserialize(std::vector<char> &data)
{
    this->_PlayerId = BinaryConversion::consume<int>(data);

    this->deserializePlayer(data);
}

void APlayerDTO::setPlayerId(const int PlayerId)
{
    this->_PlayerId = PlayerId;
}

int APlayerDTO::getPlayerId() const
{
    return this->_PlayerId;
}
