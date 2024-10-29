/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** UUIDException
*/

#include "UUIDException.hpp"

UUIDException::UUIDException(std::string message): _message{
    std::move(message)
} {
}

const char *UUIDException::what() const noexcept {
    return _message.c_str();
}
