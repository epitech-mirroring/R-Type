/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityDeletionDTO.hpp
*/

#ifndef ENTITYDELETIONDTO_HPP
#define ENTITYDELETIONDTO_HPP

#include "AEntityDTO.hpp"

class EntityDeletionDTO final : public AEntityDTO {
public:
	EntityDeletionDTO();
	EntityDeletionDTO(int entityId, IEntity::EntityType entityType);
	~EntityDeletionDTO() override = default;

	IDTO *clone() override;

	std::vector<char> serializeEntity() override;
	void deserializeEntity(std::vector<char>& data) override;
};

#endif //ENTITYDELETIONDTO_HPP
