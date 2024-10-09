/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AShip.hpp
*/

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AEntity.hpp"

class AShip : public AEntity {
public:
	explicit AShip(int id);
	~AShip() override = default;

	void update(float elapsedTime, EntityManager &entityManager) override = 0;

	void setLife(int life);
	void setShooting(bool isShooting);
	void setShootCooldown(float shootCooldown);
	void setCurrentShootCooldown(float currentShootCooldown);

	[[nodiscard]] int getLife() const;
	[[nodiscard]] bool isShooting() const;
	[[nodiscard]] float getShootCooldown() const;
	[[nodiscard]] float getCurrentShootCooldown() const;

	void removeLife(int life);

protected:
	int _life;
	bool _isShooting;
	float _shootCooldown;
	float _currentShootCooldown;
};

#endif //ASHIP_HPP
