/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ClassicBullet.hpp
*/

#ifndef CLASSICBULLET_HPP
#define CLASSICBULLET_HPP

#include "ABullet.hpp"

/**
 * @class ClassicBullet
 * @brief Class of the classic bullet
 * @inherit ABullet
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
class ClassicBullet final: public ABullet {
public:
	/**
     * @brief The constructor of the ClassicBullet class
     * @param id The id of the bullet
     * @param direction The direction of the bullet
     * @param posX The x position of the bullet
     * @param posY The y position of the bullet
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    ClassicBullet(int id, EntityDirection direction, float posX, float posY);

	/**
     * @brief The destructor of the ClassicBullet class
     * @version v0.1.0
     * @since v0.1.0
     * @author Marius PAIN
     */
    ~ClassicBullet() override = default;
};

#endif //CLASSICBULLET_HPP
