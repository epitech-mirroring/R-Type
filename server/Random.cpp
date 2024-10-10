/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Random.cpp
*/

#include "Random.hpp"

#include <random>

[[maybe_unused]] unsigned long Random::getRandom()
{
	std::random_device randD;
	std::mt19937 gen(randD());
	const unsigned long random = gen();
    return random;
}
