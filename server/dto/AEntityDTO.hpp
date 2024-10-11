/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** AEntityDTO.hpp
*/

#ifndef AENTITYDTO_HPP
#define AENTITYDTO_HPP

#include "IDTO.hpp"
#include "../entities/IEntity.hpp"

class AEntityDTO : public IDTO {
public:
    AEntityDTO(int entityId, IEntity::EntityType entityType);
    ~AEntityDTO() override = default;

    std::vector<char> serialize() override;
    void deserialize(std::vector<char> &data) override;
    IDTO *clone() override = 0;

    void setEntityId(int entityId);
    [[nodiscard]] int getEntityId() const;
    void setEntityType(IEntity::EntityType entityType);
    [[nodiscard]] IEntity::EntityType getEntityType() const;
protected:
    virtual std::vector<char> serializeEntity() = 0;
    virtual void deserializeEntity(std::vector<char> &data) = 0;

    int _entityId;
    IEntity::EntityType _entityType;
};

#endif //AENTITYDTO_HPP
