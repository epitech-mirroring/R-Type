/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ClassicBullet.cpp
*/

#include "ClassicBullet.hpp"

ClassicBullet::ClassicBullet(const int entityId, const EntityDirection direction, const float posX, const float posY) : ABullet(entityId)
{
	this->_entityType = BULLET;
    this->_damage = 1;
	this->_life = 1;
    this->_speed = 400;
    this->_directions = {direction};
    this->_posX = posX;
    this->_posY = posY;
	this->_width = 60;
	this->_height = 15;
}
