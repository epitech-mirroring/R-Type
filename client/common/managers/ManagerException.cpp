/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** ManagerException
*/

#include "ManagerException.hpp"

ManagerException::ManagerException(std::string message): _message{std::move(message)}
{
}

const char* ManagerException::what() const noexcept
{
    return _message.c_str();
}
