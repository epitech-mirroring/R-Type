/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** ClassicBullet.hpp
*/

#ifndef CLASSICBULLET_HPP
#define CLASSICBULLET_HPP

#include "ABullet.hpp"

class ClassicBullet final: public ABullet {
    public:
        ClassicBullet(int id, EntityDirection direction, int posX, int posY);
        ~ClassicBullet() override = default;

};



#endif //CLASSICBULLET_HPP
