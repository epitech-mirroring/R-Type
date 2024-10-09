/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AShip.cpp
*/

#include "AShip.hpp"

AShip::AShip(const int entityId):
	AEntity(entityId, 0, 0, 0, 0, 0, NONE)
{
	this->_life = 1;
	this->_isShooting = false;
	this->_shootCooldown = 0;
	this->_currentShootCooldown = 0;
}

void AShip::setLife(const int life)
{
	this->_life = life;
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

int AShip::getLife() const
{
	return this->_life;
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
