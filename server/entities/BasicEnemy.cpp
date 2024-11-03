/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** BasicEnemy.cpp
*/

#include "BasicEnemy.hpp"

#include <algorithm>
#include "ClassicBullet.hpp"
#include <iostream>

BasicEnemy::BasicEnemy(const int entityId, const float posY) : AShip(entityId)
{
	this->_directions = {LEFT};
	this->_entityType = ENEMY;
	this->_speed = 100;
	this->_width = 60;
	this->_height = 110;
	this->_life = 1;
	this->_damage = 1;
	this->_isShooting = true;
	this->_shootCooldown = 8.0;
	this->_currentShootCooldown = 0;
	this->_posX = 1920;
	this->_posY = std::min<float>(std::max<float>(posY, 0.F), static_cast<float>(1080 - 200));
}

void BasicEnemy::update(const float elapsedTime, EntityManager &entityManager)
{
	this->move(elapsedTime);
	if (static_cast<int>(this->_posX) < -this->_width) {
		this->_life = 0;
		this->_isShooting = false;
    }
	if (this->_isShooting) {
		this->_currentShootCooldown += elapsedTime;
		if (this->_currentShootCooldown >= this->_shootCooldown) {
			this->_currentShootCooldown = this->_currentShootCooldown - this->_shootCooldown;
			IEntity *bullet = new ClassicBullet(entityManager.getNewId(), LEFT, this->_posX - (this->_width + 10), this->_posY + (this->_height / 2));
			entityManager.addEntityToCreationBuffer(bullet);
		}
	}
}
