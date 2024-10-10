/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"

AEntity::AEntity(const int entityId, const float posX, const float posY,
    const int width, const int height, const float speed, const int damage,
    const int life, const EntityDirection direction):
    _id(entityId), _posX(posX), _posY(posY), _speed(speed),
    _width(width), _height(height), _damage(damage), _life(life),
    _direction(direction)
{
}

void AEntity::setId(const int entityId)
{
    this->_id = entityId;
}

void AEntity::setPosX(const float posX)
{
    this->_posX = posX;
}

void AEntity::setPosY(const float posY)
{
    this->_posY = posY;
}

void AEntity::setSpeed(const float speed)
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

void AEntity::setDamage(const int damage)
{
    this->_damage = damage;
}

void AEntity::setLife(const int life)
{
    this->_life = life;
}

void AEntity::setDirection(const EntityDirection direction)
{
    this->_direction = direction;
}

int AEntity::getId() const
{
    return this->_id;
}

float AEntity::getPosX() const
{
    return this->_posX;
}

float AEntity::getPosY() const
{
    return this->_posY;
}

float AEntity::getSpeed() const
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

int AEntity::getDamage() const
{
    return this->_damage;
}

int AEntity::getLife() const
{
    return this->_life;
}

IEntity::EntityDirection AEntity::getDirection() const
{
    return this->_direction;
}

void AEntity::move(const float elapsedTime)
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
