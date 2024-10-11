/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityCreationDTO.hpp
*/

#ifndef ENTITYCREATIONDTO_HPP
#define ENTITYCREATIONDTO_HPP

#include "AEntityDTO.hpp"

class EntityCreationDTO final: public AEntityDTO {
public:
	EntityCreationDTO();
	EntityCreationDTO(int entityId, IEntity::EntityType entityType, int posX, int posY);
	~EntityCreationDTO() override = default;

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

#endif //ENTITYCREATIONDTO_HPP
