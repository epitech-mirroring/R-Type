/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOException.cpp
*/

#include "NetworkException.hpp"

NetworkException::NetworkException(std::string message) : _message(std::move(message)) {}

const char *NetworkException::what() const noexcept
{
    return _message.c_str();
}
