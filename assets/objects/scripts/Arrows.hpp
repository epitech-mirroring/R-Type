/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Arrows.hpp
*/

#ifndef ARROWS_HPP
#define ARROWS_HPP

#include <string>

#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"
#include "StellarForge/Common/managers/ObjectManager.hpp"
#include "StellarForge/Common/managers/SceneManager.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"

#include <unordered_map>
#include <typeindex>
#include <vector>

class Arrows final : public CPPMonoBehaviour {
public:
    Arrows(IObject *owner, const json::JsonObject *data);
    ~Arrows() override = default;

    void start() override;
    void update() override;

    void manageArrows(const EventData &data);
    void showArrows(const EventData &data);

    IComponent *clone(IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() const override;

private:
  bool _isFiring = false;
  bool _isShowing = false;
};

#endif //ARROWS_HPP
