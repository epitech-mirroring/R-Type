/*
** EPITECH PROJECT, 2024
** JSON
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#pragma once
#include "IJsonObject.hpp"
#include "IJsonPrimitiveObject.hpp"
#include "common/UncertainBool.hpp"

namespace json {
    union JsonNumberValue {
        int i;
        float f;
    };

    class JsonNumber final : public IJsonPrimitiveObject<JsonNumberValue> {
    protected:
        std::string _name;
        JsonNumberValue _value;
        uncertain_bool _isFloat;

    public:
        explicit JsonNumber(std::string name = "");

        JsonNumber(int value, std::string name = ""); // NOLINT(*-explicit-conversions)

        JsonNumber(float value, std::string name = ""); // NOLINT(*-explicit-conversions)

        ~JsonNumber() override = default;

        [[nodiscard]]
        std::string stringify() const override;

        void parse(const IJsonParser &parser, const std::string &string) override;

        [[nodiscard]]
        JsonType getType() const override;

        [[nodiscard]]
        std::string getName() const override;

        [[nodiscard]]
        int getIntValue() const;

        [[nodiscard]]
        float getFloatValue() const;

        [[nodiscard]]
        bool isFloat() const;

        [[nodiscard]]
        JsonNumberValue getValue() const override;

        void setValue(int value);

        void setValue(float value);

        explicit operator int() const;

        explicit operator float() const;

        void setValue(const JsonNumberValue &value) override;

        explicit operator json::JsonNumberValue() const override;
    };
}
