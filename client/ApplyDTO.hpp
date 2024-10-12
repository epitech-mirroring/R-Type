/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
*/

#ifndef R_TYPE_REBORN_APPLYDTO_HPP
#define R_TYPE_REBORN_APPLYDTO_HPP

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <vector>
#include "../server/dto/DTORegistry.hpp"
#include "../server/dto/DTODecoder.hpp"
#include "../server/dto/entity/EntityCreationDTO.hpp"
#include "../server/dto/entity/EntityDeletionDTO.hpp"
#include "../server/dto/entity/EntityPositionDTO.hpp"
#include "../server/dto/player/PlayerActionStartDTO.hpp"
#include "../server/dto/player/PlayerActionStopDTO.hpp"

void applyDTO(EntityCreationDTO *dto);
void applyDTO(EntityDeletionDTO *dto);
void applyDTO(EntityPositionDTO *dto);
void applyDTO(PlayerActionStartDTO *dto);
void applyDTO(PlayerActionStopDTO *dto);

void applyDTOs(std::vector<char> data, DTORegistry *dtoRegistry);

#endif // R_TYPE_REBORN_APPLYDTO_HPP