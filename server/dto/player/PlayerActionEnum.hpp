/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** PlayerActionEnum.hpp
*/

#ifndef PLAYERACTIONENUM_HPP
#define PLAYERACTIONENUM_HPP

#include <cstdint>

/**
 * @enum PlayerAction
 * @brief All the possible actions for the player
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
enum PlayerAction : std::uint8_t {
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT,
	SHOOT
};

#endif // PLAYERACTIONENUM_HPP
