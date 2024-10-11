/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityPositionDTO.hpp
*/

#ifndef ENTITYPOSITIONDTO_HPP
#define ENTITYPOSITIONDTO_HPP

#include "AEntityDTO.hpp"

class EntityPositionDTO final : public AEntityDTO {
public:
	EntityPositionDTO();
	EntityPositionDTO(int entityId, IEntity::EntityType entityType, int posX, int posY);
	~EntityPositionDTO() override = default;

	IDTO *clone() override;

	void setPosX(int posX);
	[[nodiscard]] int getPosX() const;
	void setPosY(int posY);
	[[nodiscard]] int getPosY() const;

    std::vector<char> serializeEntity() override;
	void deserializeEntity(std::vector<char>& data) override;

private:
	int _posX;
	int _posY;
};

#endif //ENTITYPOSITIONDTO_HPP
