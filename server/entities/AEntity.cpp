/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntity.cpp
*/

#include "AEntity.hpp"
#include <algorithm>
#include <iostream>

AEntity::AEntity(const int entityId, const EntityType entityType, const float posX, const float posY,
    const int width, const int height, const float speed, const int damage,
    const int life, const std::vector<EntityDirection>& direction):
    _id(entityId), _entityType(entityType), _posX(posX), _posY(posY), _speed(speed),
    _width(width), _height(height), _damage(damage), _life(life),
    _directions(direction)
{
}

bool AEntity::isColliding(IEntity *entity) const
{
    return this->_posX < entity->getPosX() + static_cast<float>(entity->getWidth()) &&
        this->_posX + static_cast<float>(this->_width) > entity->getPosX() &&
        this->_posY < entity->getPosY() + static_cast<float>(entity->getHeight()) &&
        this->_posY + static_cast<float>(this->_height) > entity->getPosY();
}

void AEntity::onCollision(IEntity* entity)
{
    this->_life -= entity->getDamage();
}

void AEntity::setId(const int entityId)
{
    this->_id = entityId;
}

void AEntity::setEntityType(const EntityType entityType)
{
    this->_entityType = entityType;
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

void AEntity::setDirection(const std::vector<EntityDirection> direction)
{
    this->_directions = direction;
}

void AEntity::addDirection(const EntityDirection direction)
{
    if (std::find(this->_directions.begin(), this->_directions.end(), direction) == this->_directions.end()) {
        this->_directions.push_back(direction);
    }
}

void AEntity::removeDirection(const EntityDirection direction)
{
    this->_directions.erase(std::remove(this->_directions.begin(), this->_directions.end(), direction), this->_directions.end());
}

int AEntity::getId() const
{
    return this->_id;
}

EntityType AEntity::getEntityType() const
{
    return this->_entityType;
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

std::vector<IEntity::EntityDirection> AEntity::getDirection() const
{
    return this->_directions;
}

void AEntity::move(const float elapsedTime)
{
    for (const auto &dir : this->_directions) {
        switch (dir) {
            case UP:
                this->_posY -= this->_speed * elapsedTime;
                break;
            case DOWN:
                this->_posY += this->_speed * elapsedTime;
                break;
            case LEFT:
                this->_posX -= this->_speed * elapsedTime;
                break;
            case RIGHT:
                this->_posX += this->_speed * elapsedTime;
                break;
            default:
                break;
        }
    }
}
