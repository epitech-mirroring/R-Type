/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTOEncoder.cpp
*/

#include "DTOEncoder.hpp"
#include "../utils/BinaryVector.hpp"

DTOEncoder::DTOEncoder(): _dtoRegistry(nullptr)
{
}

DTOEncoder::DTOEncoder(DTORegistry *dtoRegistry): _dtoRegistry(dtoRegistry)
{
}

std::vector<char> DTOEncoder::encode(IDTO &dto) const
{
    int dtoID = -1;

    if (this->_dtoRegistry != nullptr) {
        dtoID = this->_dtoRegistry->getDTOId(&dto);
    }
    if (dtoID == -1) {
        // TODO: Throw exception
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
