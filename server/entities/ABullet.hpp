/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ABullet.hpp
*/

#ifndef ABULLET_HPP
#define ABULLET_HPP

#include "AEntity.hpp"

class ABullet : public AEntity {
public:
	explicit ABullet(int id);
	~ABullet() override = default;

	void update(float elapsedTime, EntityManager &entityManager) override;

	void setDamage(int damage);

    [[nodiscard]] int getDamage() const;

protected:
	int _damage;


};



#endif //ABULLET_HPP
