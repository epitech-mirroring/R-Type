/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Player.hpp
*/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "AShip.hpp"
#include "EntityManager.hpp"

class Player final : public AShip {
public:
    explicit Player(int id);
    ~Player() override =  default;

    void update(float elapsedTime, EntityManager &entityManager) override;

    void setScore(int score);

    [[nodiscard]] int getScore() const;

    void addScore(int score);

private:
    int _score;
};

#endif //PLAYER_HPP
