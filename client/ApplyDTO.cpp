/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
*/

#include "ApplyDTO.hpp"
#include <iostream>

void applyDTO(EntityCreationDTO *dto)
{
    std::cout << "Applying EntityCreationDTO" << std::endl;
}

void applyDTO(EntityDeletionDTO *dto)
{
    std::cout << "Applying EntityDeletionDTO" << std::endl;
}

void applyDTO(EntityPositionDTO *dto)
{
    std::cout << "Applying EntityPositionDTO" << std::endl;
}

void applyDTO(PlayerActionStartDTO *dto)
{
    std::cout << "Applying PlayerActionStartDTO" << std::endl;
}

void applyDTO(PlayerActionStopDTO *dto)
{
    std::cout << "Applying PlayerActionStopDTO" << std::endl;
}

static const std::unordered_map<std::type_index, std::function<void(IDTO*)>> applyFunctions = {
    { typeid(EntityCreationDTO), [](IDTO* dto) { applyDTO(static_cast<EntityCreationDTO*>(dto)); } },
    { typeid(EntityDeletionDTO), [](IDTO* dto) { applyDTO(static_cast<EntityDeletionDTO*>(dto)); } },
    { typeid(EntityPositionDTO), [](IDTO* dto) { applyDTO(static_cast<EntityPositionDTO*>(dto)); } },
    { typeid(PlayerActionStartDTO), [](IDTO* dto) { applyDTO(static_cast<PlayerActionStartDTO*>(dto)); } },
    { typeid(PlayerActionStopDTO), [](IDTO* dto) { applyDTO(static_cast<PlayerActionStopDTO*>(dto)); } }
};

void applyDTOs(std::vector<char> data, DTORegistry *dtoRegistry)
{
    DTODecoder decoder(dtoRegistry);
    IDTO *dto = decoder.decode(data);

    auto it = applyFunctions.find(typeid(*dto));
    if (it != applyFunctions.end()) {
        it->second(dto);
    } else {
        std::cerr << "Unknown DTO type" << std::endl;
    }
}
