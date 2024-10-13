/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "ClassicBullet.hpp"
#include <iostream>

Player::Player(const int entityId) : AShip(entityId), _score(0)
{
	this->_directions = {NONE};
	this->_entityType = PLAYER;
	this->_posX = 50;
	this->_posY = 50;
	this->_speed = 200;
    this->_width = 180;
	this->_height = 78;
	this->_life = 1;
	this->_damage = 1;
	this->_isShooting = false;
	this->_shootCooldown = 0.5;
	this->_currentShootCooldown = 0;
}

void Player::update(const float elapsedTime, EntityManager &entityManager)
{
	this->move(elapsedTime);
	if (this->_isShooting) {
		this->_currentShootCooldown += elapsedTime;
		if (this->_currentShootCooldown >= this->_shootCooldown) {
			this->_currentShootCooldown = 0;
			IEntity* bullet = new ClassicBullet(entityManager.getNewId(), RIGHT, this->_posX + (this->_width + 10), this->_posY + this->_height / 2);
			entityManager.addEntityToCreationBuffer(bullet);
		}
	}
}

void Player::setScore(const int score)
{
	this->_score = score;
}

int Player::getScore() const
{
	return this->_score;
}

void Player::addScore(const int score)
{
	this->_score += score;
}
