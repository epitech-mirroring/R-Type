/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameSpeedDTO.cpp
*/

#include "GameSpeedDTO.hpp"
#include "../../conversion/BinaryVector.hpp"

GameSpeedDTO::GameSpeedDTO() : speed(NO_CHANGE) {}

GameSpeedDTO::GameSpeedDTO(const GameSpeedEnum speed) : speed(speed) {}

IDTO *GameSpeedDTO::clone() {
    return new GameSpeedDTO(this->speed);
}

std::vector<char> GameSpeedDTO::serialize() {
    std::vector<char> data = BinaryConversion::convert<GameSpeedEnum>(speed);
    return data;
}

void GameSpeedDTO::deserialize(std::vector<char> &data) {
    this->speed = BinaryConversion::consume<GameSpeedEnum>(data);
}

GameSpeedEnum GameSpeedDTO::getSpeed() const {
    return this->speed;
}

void GameSpeedDTO::setSpeed(const GameSpeedEnum speed) {
    this->speed = speed;
}
