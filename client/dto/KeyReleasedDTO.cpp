/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** KeyReleasedDTO.cpp
*/

#include "KeyReleasedDTO.hpp"
#include "../utils/BinaryVector.hpp"


KeyReleasedDTO::KeyReleasedDTO(): APlayerDTO(-1)
{
}

KeyReleasedDTO::KeyReleasedDTO(const int entityId, std::string key)
	: APlayerDTO(entityId), _key(key)
{
}

IDTO *KeyReleasedDTO::clone()
{
	return new KeyReleasedDTO();
}

std::vector<char> KeyReleasedDTO::serializePlayer()
{
	std::vector<char> data = BinaryConversion::convert<std::string>(this->_key);
	return data;
}

void KeyReleasedDTO::deserializePlayer(std::vector<char> &data)
{
	this->_key = BinaryConversion::consume<std::string>(data);
}
