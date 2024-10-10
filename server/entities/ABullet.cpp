/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"

ABullet::ABullet(const int entityId) : AEntity(entityId, 0, 0, 0, 0, 0, 0, 0, NONE)
{
}

void ABullet::update(const float elapsedTime, EntityManager &entityManager)
{
    (void)(entityManager);
    this->move(elapsedTime);
}
