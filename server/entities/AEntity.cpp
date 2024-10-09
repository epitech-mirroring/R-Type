/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(int id, int posX, int posY, int width, int height, int speed, IEntity::EntityDirection direction)
{
    this->_id = id;
    this->_posX = posX;
    this->_posY = posY;
    this->_width = width;
    this->_height = height;
    this->_speed = speed;
    this->_direction = direction;
}

void AEntity::setPosX(const int posX)
{
    this->_posX = posX;
}

void AEntity::setPosY(const int posY)
{
    this->_posY = posY;
}

void AEntity::setSpeed(const int speed)
{
    this->_speed = speed;
}

void AEntity::setWidth(const int width)
{
    this->_width = width;
}

void AEntity::setHeight(const int height)
{
    this->_height = height;
}

void AEntity::setDirection(const EntityDirection direction)
{
    this->_direction = direction;
}

int AEntity::getId() const
{
    return this->_id;
}

int AEntity::getPosX() const
{
    return this->_posX;
}

int AEntity::getPosY() const
{
    return this->_posY;
}

int AEntity::getSpeed() const
{
    return this->_speed;
}

int AEntity::getWidth() const
{
    return this->_width;
}

int AEntity::getHeight() const
{
    return this->_height;
}

IEntity::EntityDirection AEntity::getDirection() const
{
    return this->_direction;
}

void AEntity::move(float elapsedTime)
{
    switch (this->_direction) {
    case UP:
        this->_posY -= this->_speed * elapsedTime;
        break;
    case UP_LEFT:
        this->_posY -= this->_speed * elapsedTime;
        this->_posX -= this->_speed * elapsedTime;
        break;
    case UP_RIGHT:
        this->_posY -= this->_speed * elapsedTime;
        this->_posX += this->_speed * elapsedTime;
        break;
    case DOWN:
        this->_posY += this->_speed * elapsedTime;
        break;
    case DOWN_LEFT:
        this->_posY += this->_speed * elapsedTime;
        this->_posX -= this->_speed * elapsedTime;
        break;
    case DOWN_RIGHT:
        this->_posY += this->_speed * elapsedTime;
        this->_posX += this->_speed * elapsedTime;
        break;
    case LEFT:
        this->_posX -= this->_speed * elapsedTime;
        break;
    case RIGHT:
        this->_posX += this->_speed * elapsedTime;
        break;
    case NONE:
        break;
    }
}
