/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#pragma once
#include <string>
#include "IJsonObject.hpp"
#include "IJsonPrimitiveObject.hpp"

namespace json {
    class JsonString : public IJsonPrimitiveObject<std::string> {
    protected:
        std::string _value;
        std::string _name;

    public:
        JsonString(std::string value = "", std::string name = "");

        ~JsonString() override = default;

        [[nodiscard]]
        std::string getValue() const override;

        void setValue(const std::string &value) override;

        [[nodiscard]]
        std::string stringify() const override;

        void parse(const IJsonParser &parser, const std::string &string) override;

        [[nodiscard]]
        JsonType getType() const override;

        [[nodiscard]]
        std::string getName() const override;

        explicit operator std::string() const override;
    };
}
