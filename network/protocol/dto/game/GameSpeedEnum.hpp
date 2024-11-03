/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** GameSpeedEnum.hpp
*/

#ifndef GAMESPEEDENUM_HPP
#define GAMESPEEDENUM_HPP

#include <cstdint>

/**
 * @enum GameSpeedEnum
 * @brief Enum for Game Speed
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
enum GameSpeedEnum : std::uint8_t {
    NO_CHANGE = 0,
    SLOWER = 1,
    FASTER = 2
};

#endif //GAMESPEEDENUM_HPP
