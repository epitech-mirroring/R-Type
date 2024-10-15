/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.hpp
*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <chrono>
#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "common/json/JsonObject.hpp"

class Background final : public CPPMonoBehaviour {
    public:
        Background(IObject *owner, const json::IJsonObject *data);
        ~Background() override = default;

        void start() override;
        void update() override;

        void setSpeed(float newSpeed);
        [[nodiscard]] float getSpeed() const;

        IComponent *clone (IObject *owner) const override;
        void deserialize(const json::IJsonObject *data) override;
        void end() override;
        json::IJsonObject *serializeData() override;
    private:
        float speed = 1.00f;
        std::chrono::time_point<std::chrono::system_clock> startTime;
        std::chrono::time_point<std::chrono::system_clock> actualTime;
};

#endif //BACKGROUND_HPP
