/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** BasicEnemy.hpp
*/

#ifndef BASICENEMY_HPP
#define BASICENEMY_HPP

#include "AShip.hpp"
#include "EntityManager.hpp"

class BasicEnemy final : public AShip {
public:
	explicit BasicEnemy(int id, int posY);
	~BasicEnemy() override = default;

	void update(float elapsedTime, EntityManager& entityManager) override;

};



#endif //BASICENEMY_HPP
