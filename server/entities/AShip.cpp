/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AShip.cpp
*/

#include "AShip.hpp"

AShip::AShip(const int entityId):
	AEntity(entityId, NO_TYPE, 0, 0, 0, 0, 0, 0, 0, {NONE}),
	_isShooting(false), _shootCooldown(0), _currentShootCooldown(0)
{
}

void AShip::setShooting(const bool isShooting)
{
	this->_isShooting = isShooting;
}

void AShip::setShootCooldown(const float shootCooldown)
{
	this->_shootCooldown = shootCooldown;
}

void AShip::setCurrentShootCooldown(const float currentShootCooldown)
{
	this->_currentShootCooldown = currentShootCooldown;
}

bool AShip::isShooting() const
{
	return this->_isShooting;
}

float AShip::getShootCooldown() const
{
	return this->_shootCooldown;
}

float AShip::getCurrentShootCooldown() const
{
	return this->_currentShootCooldown;
}

void AShip::removeLife(const int life)
{
	this->_life -= life;
}
