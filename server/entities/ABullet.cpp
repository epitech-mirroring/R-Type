/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ABullet.cpp
*/

#include "ABullet.hpp"

ABullet::ABullet(const int id) : AEntity(id, 0, 0, 0, 0, 0, NONE)
{
	this->_damage = 1;
}

void ABullet::update(float elapsedTime, EntityManager &entityManager)
{
    this->move(elapsedTime);
}

void ABullet::setDamage(const int damage)
{
    this->_damage = damage;
}

int ABullet::getDamage() const
{
    return this->_damage;
}
