/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityTypeEnum.hpp
*/

#ifndef ENTITYTYPEENUM_HPP
#define ENTITYTYPEENUM_HPP

#include <cstdint>

/**
 * @enum EntityType
 * @brief All the possible types for the entities
 * @version v0.1.0
 * @since v0.1.0
 * @author Marius PAIN
 */
enum EntityType : std::uint8_t {
    NO_TYPE,
    PLAYER,
    ENEMY,
    BULLET
};

#endif // ENTITYTYPEENUM_HPP
