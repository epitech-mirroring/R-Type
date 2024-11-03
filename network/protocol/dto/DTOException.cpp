/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOException.cpp
*/

#include "DTOException.hpp"

#include <utility>

DTOException::DTOException(std::string message) : _message(std::move(message))
{
}

const char *DTOException::what() const noexcept
{
    return _message.c_str();
}
