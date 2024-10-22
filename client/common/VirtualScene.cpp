/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** VirtualScene.cpp
*/

#include "VirtualScene.hpp"

#include <utility>

VirtualScene::VirtualScene(std::vector<IObject*> objects) : _objects(std::move(objects))
{
}

void VirtualScene::runScene()
{
    for (const auto& object : _objects)
    {
        object->runObject();
    }
}

std::vector<IObject*> VirtualScene::getObjects() const
{
    return _objects;
}

void VirtualScene::addObject(IObject* object)
{
    _objects.push_back(object);
}

void VirtualScene::removeObject(IObject* object)
{
    for (auto ite = _objects.begin(); ite != _objects.end(); ++ite)
    {
        if (*ite == object)
        {
            _objects.erase(ite);
            return;
        }
    }
}
