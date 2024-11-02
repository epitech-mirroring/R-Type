/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTORegistry.cpp
*/

#include "DTORegistry.hpp"
#include "entity/EntityCreationDTO.hpp"
#include "entity/EntityDeletionDTO.hpp"
#include "entity/EntityPositionDTO.hpp"
#include "player/PlayerActionStartDTO.hpp"
#include "player/PlayerActionStopDTO.hpp"
#include "tcp/TCPSendIdDTO.hpp"
#include "tcp/TCPCreateUDPEndpointDTO.hpp"

#include <typeinfo>

DTORegistry::DTORegistry()
{
    this->_dtos = {
        new EntityCreationDTO(),
        new EntityDeletionDTO(),
        new EntityPositionDTO(),
        new PlayerActionStartDTO(),
        new PlayerActionStopDTO(),
        new TCPSendIdDTO(),
        new TCPCreateUDPEndpointDTO()
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
