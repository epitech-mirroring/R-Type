/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOEncoder.cpp
*/

#include "DTOEncoder.hpp"
#include "../conversion/BinaryVector.hpp"

DTOEncoder::DTOEncoder(DTORegistry *dtoRegistry): _dtoRegistry(dtoRegistry)
{
}

std::vector<char> DTOEncoder::encode(IDTO &dto) const
{
    if (this->_dtoRegistry == nullptr) {
        throw DTOException("DTORegistry is not set");
    }
    const int dtoID = this->_dtoRegistry->getDTOId(&dto);
    if (dtoID == -1) {
        throw DTOException("DTO not found in registry");
    }
    std::vector<char> data = BinaryConversion::convert<int>(dtoID);
    data += dto.serialize();
    return data;
}

DTORegistry &DTOEncoder::getDTORegistry() const
{
    return *this->_dtoRegistry;
}

void DTOEncoder::setDTORegistry(DTORegistry *dtoRegistry)
{
    this->_dtoRegistry = dtoRegistry;
}
