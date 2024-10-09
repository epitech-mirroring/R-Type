/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ClassicBullet.cpp
*/

#include "ClassicBullet.hpp"

ClassicBullet::ClassicBullet(const int id, const EntityDirection direction, const int posX, const int posY) : ABullet(id)
{
    this->_damage = 1;
    this->_speed = 15;
    this->_direction = direction;
    this->_posX = posX;
    this->_posY = posY;
	this->_width = 10;
	this->_height = 5;
}
