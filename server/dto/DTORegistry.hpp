/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** DTORegistry.hpp
*/

#ifndef DTOREGISTRY_HPP
#define DTOREGISTRY_HPP

#include "IDTO.hpp"
#include <vector>

class DTORegistry {
public:
	DTORegistry();
	~DTORegistry();

	int getDTOId(const IDTO *dto) const;
    [[nodiscard]] IDTO *getDTOById(int dtoID) const;

private:
	std::vector<IDTO *> _dtos;
};

#endif //DTOREGISTRY_HPP
