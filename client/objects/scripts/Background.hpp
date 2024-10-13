/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.hpp
*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <ctime>
#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "common/json/JsonObject.hpp"
#include "NetworkManager.hpp"

class Background final : public CPPMonoBehaviour {
    public:
        Background(IObject *owner, const json::IJsonObject *data);
        ~Background() = default;

        Transform *getOwnerTransform();
        void start() override;
        void update() override;

        void setSpeed(float newSpeed);
        float getSpeed();

        IComponent *clone (IObject *owner) const override;
        void deserialize(const json::IJsonObject *data) override;
        void end() override;
        json::IJsonObject *serializeData() override;
    private:
        float speed = 1.00f;
        clock_t startTime;
};

#endif //BACKGROUND_HPP
