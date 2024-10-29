/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#pragma once
#include "IJsonObject.hpp"
#include "IJsonPrimitiveObject.hpp"

namespace json {
    class JsonBoolean final : public IJsonPrimitiveObject<bool> {
    protected:
        bool _value;
        std::string _name;

    public:
        JsonBoolean(bool value = false, std::string name = "");

        ~JsonBoolean() override = default;

        [[nodiscard]]
        std::string stringify() const override;

        void parse(const IJsonParser &parser,
                   const std::string &string) override;

        [[nodiscard]]
        JsonType getType() const override;

        [[nodiscard]]
        std::string getName() const override;

        [[nodiscard]]
        bool getValue() const override;

        void setValue(const bool &value) override;

        explicit operator bool() const override;
    };
}
