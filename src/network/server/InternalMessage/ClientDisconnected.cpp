/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "ClientDisconnected.hpp"

int ClientDisconnected::getId() const
{
    return std::stoi(_id);
}

std::string ClientDisconnected::getMessage() const
{
    return _message;
}
