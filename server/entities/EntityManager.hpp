/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** EntityManager.hpp
*/

#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <unordered_map>

#include "IEntity.hpp"

class EntityManager {
public:
	EntityManager() = default;
	~EntityManager() = default;

	void addEntity(IEntity *entity);

	std::unordered_map<int, IEntity *> &getEntities();
    void deleteEntity(int id);
    void deleteAllEntities();
    IEntity *getEntity(int id);

	void updateEntities(float deltaTime);
	void updateEntity(int id, float deltaTime);
    void updateEntity(IEntity *entity, float deltaTime);

	int getNewId();

private:
	std::unordered_map<int, IEntity *> _entities;
	int _idCounter;
};

#endif //ENTITYMANAGER_HPP
