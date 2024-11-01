/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTODecoder.cpp
*/

#include "DTODecoder.hpp"
#include "../conversion/BinaryVector.hpp"

DTODecoder::DTODecoder(DTORegistry *dtoRegistry): _dtoRegistry(dtoRegistry)
{
}

IDTO *DTODecoder::decode(std::vector<char> &data) const
{
	if (this->_dtoRegistry == nullptr) {
		throw DTOException("DTORegistry is not set");
	}
	const int dtoId = BinaryConversion::consume<int>(data);
	IDTO *dto = this->_dtoRegistry->getDTOById(dtoId)->clone();
	if (dto == nullptr) {
        throw DTOException("DTO not found in registry");
    }
	dto->deserialize(data);
	return dto;
}

DTORegistry &DTODecoder::getDTORegistry() const
{
	return *this->_dtoRegistry;
}

void DTODecoder::setDTORegistry(DTORegistry *dtoRegistry)
{
	this->_dtoRegistry = dtoRegistry;
}
