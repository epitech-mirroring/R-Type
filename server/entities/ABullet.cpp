/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"

ABullet::ABullet(const int entityId) : AEntity(entityId, NO_TYPE, 0, 0, 0, 0, 0, 0, 0, {NONE})
{
}

void ABullet::update(const float elapsedTime, EntityManager &entityManager)
{
    (void)entityManager;
    this->move(elapsedTime);
    if (static_cast<int>(this->_posX) < -this->_width || static_cast<int>(this->_posX) > 1920) {
        this->_life = 0;
    }
}
