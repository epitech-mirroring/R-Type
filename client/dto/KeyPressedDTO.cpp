/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** KeyPressedDTO.cpp
*/

#include "KeyPressedDTO.hpp"
#include "../utils/BinaryVector.hpp"


KeyPressedDTO::KeyPressedDTO(): APlayerDTO(-1)
{
}

KeyPressedDTO::KeyPressedDTO(const int entityId, std::string key)
	: APlayerDTO(entityId), _key(key)
{
}

IDTO *KeyPressedDTO::clone()
{
	return new KeyPressedDTO();
}

std::vector<char> KeyPressedDTO::serializePlayer()
{
	std::vector<char> data = BinaryConversion::convert<std::string>(this->_key);
	return data;
}

void KeyPressedDTO::deserializePlayer(std::vector<char> &data)
{
	this->_key = BinaryConversion::consume<std::string>(data);
}

void KeyPressedDTO::setKey(const std::string key)
{
	this->_key = key;
}

std::string KeyPressedDTO::getKey() const
{
	return this->_key;
}
