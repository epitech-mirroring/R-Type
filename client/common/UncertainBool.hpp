/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef UNCERTAINBOOL_HPP
#define UNCERTAINBOOL_HPP
#include <cstdint>

using uncertain_bool = enum UncertainBool: uint8_t {
    TRUE = 1u,
    FALSE = 0u,
    UNCERTAIN = 2u
};

#endif //UNCERTAINBOOL_HPP
