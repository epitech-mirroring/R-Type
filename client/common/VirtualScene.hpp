/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** VirtualScene.hpp
*/

#ifndef VIRTUALSCENE_HPP
#define VIRTUALSCENE_HPP

#include "IScene.hpp"

class VirtualScene final : public IScene
{
protected:
    std::vector<IObject*> _objects;

public:
    explicit VirtualScene(std::vector<IObject*> objects = {});
    ~VirtualScene() override = default;

    void runScene() override;
    [[nodiscard]] std::vector<IObject*> getObjects() const override;
    void addObject(IObject* object) override;
    void removeObject(IObject* object) override;
};


#endif //VIRTUALSCENE_HPP
