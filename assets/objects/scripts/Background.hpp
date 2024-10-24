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
    #ifdef __linux__
        std::chrono::system_clock::time_point startTime;
        std::chrono::system_clock::time_point actualTime;
    #else
        std::chrono::steady_clock::time_point startTime;
        std::chrono::steady_clock::time_point actualTime;
    #endif


};

#endif //BACKGROUND_HPP
