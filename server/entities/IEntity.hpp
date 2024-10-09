/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IEntity.hpp
*/

#ifndef IENTITY_HPP
#define IENTITY_HPP

class EntityManager; // Forward declaration

class IEntity {
public:
	enum EntityDirection {
		UP,
    	UP_LEFT,
        UP_RIGHT,
		DOWN,
        DOWN_LEFT,
        DOWN_RIGHT,
        LEFT,
        RIGHT,
        NONE,
	};

	virtual ~IEntity() = default;

	virtual void update(float elapsedTime, EntityManager &entityManager) = 0;

	[[nodiscard]] virtual int getId() const = 0;
    [[nodiscard]] virtual int getPosX() const = 0;
    [[nodiscard]] virtual int getPosY() const = 0;
    [[nodiscard]] virtual int getSpeed() const = 0;
    [[nodiscard]] virtual int getWidth() const = 0;
    [[nodiscard]] virtual int getHeight() const = 0;
    [[nodiscard]] virtual IEntity::EntityDirection getDirection() const = 0;
};



#endif //IENTITY_HPP
