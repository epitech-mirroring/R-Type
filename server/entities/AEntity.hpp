/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntity.hpp
*/

#ifndef AENTITY_HPP
#define AENTITY_HPP

#include "IEntity.hpp"

class AEntity : public IEntity {
public:
    void update(float elapsedTime, EntityManager &entityManager) override = 0;

	[[nodiscard]] int getId() const override;
    [[nodiscard]] int getPosX() const override;
    [[nodiscard]] int getPosY() const override;
    [[nodiscard]] int getSpeed() const override;
    [[nodiscard]] int getWidth() const override;
    [[nodiscard]] int getHeight() const override;
    [[nodiscard]] EntityDirection getDirection() const override;

protected:
	AEntity(int _id, int posX, int posY, int speed, int width, int height, IEntity::EntityDirection direction);

	void setPosX(int posX);
	void setPosY(int posY);
	void setSpeed(int speed);
	void setWidth(int width);
	void setHeight(int height);
	void setDirection(EntityDirection direction);

    void move(float elapsedTime);

    int _id;
    int _posX;
	int _posY;
    int _speed;
    int _width;
    int _height;
    EntityDirection _direction;

};



#endif //AENTITY_HPP
