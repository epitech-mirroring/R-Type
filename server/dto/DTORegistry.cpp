/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTORegistry.cpp
*/

#include "DTORegistry.hpp"
#include "EntityCreationDTO.hpp"
#include "EntityDeletionDTO.hpp"
#include "EntityPositionDTO.hpp"
#include <typeinfo>


DTORegistry::DTORegistry()
{
    this->_dtos = {
        new EntityCreationDTO(),
        new EntityDeletionDTO(),
        new EntityPositionDTO()
    };
}

DTORegistry::~DTORegistry()
{
	this->_dtos.clear();
}

int DTORegistry::getDTOId(const IDTO *dto) const
{
    for (int i = 0; i < this->_dtos.size(); i++) {
        if (typeid(*this->_dtos[i]) == typeid(*dto)) { // TODO: Check if this is the correct way to compare types
            return i;
        }
    }
    return -1;
}

IDTO *DTORegistry::getDTOById(const int dtoID) const
{
    return this->_dtos[dtoID];
}
