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
#include "PlayerStartMoveDown.hpp"
#include "PlayerStartMoveRight.hpp"
#include "PlayerStartMoveLeft.hpp"
#include "PlayerStartMoveUp.hpp"
#include "PlayerStopMoveDown.hpp"
#include "PlayerStopMoveRight.hpp"
#include "PlayerStopMoveLeft.hpp"
#include "PlayerStopMoveUp.hpp"
#include "PlayerStopShoot.hpp"
#include "PlayerStartShoot.hpp"
#include <typeinfo>


DTORegistry::DTORegistry()
{
    this->_dtos = {
        new EntityCreationDTO(),
        new EntityDeletionDTO(),
        new EntityPositionDTO(),
        new PlayerStartMoveDown(),
        new PlayerStartMoveRight(),
        new PlayerStartMoveLeft(),
        new PlayerStartMoveUp(),
        new PlayerStopMoveDown(),
        new PlayerStopMoveRight(),
        new PlayerStopMoveLeft(),
        new PlayerStopMoveUp(),
        new PlayerStopShoot(),
        new PlayerStartShoot()
    };
}

DTORegistry::~DTORegistry()
{
	this->_dtos.clear();
}

int DTORegistry::getDTOId(const IDTO *dto) const
{
    for (int i = 0; i < this->_dtos.size(); i++) {
        if (typeid(*this->_dtos[i]) == typeid(*dto)) {
            return i;
        }
    }
    return -1;
}

IDTO *DTORegistry::getDTOById(const int dtoID) const
{
    if (dtoID < 0 || dtoID >= this->_dtos.size()) {
        return nullptr;
    }
    return this->_dtos[dtoID];
}
