
/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#pragma once
#include <string>
#include <cstdint>
#include <unordered_map>

namespace json {
    class IJsonParser;
}

namespace json {
    enum JsonType: uint8_t {
        OBJECT,
        ARRAY,
        STRING,
        NUMBER,
        BOOLEAN,
        NULL_VALUE
    };

    class IJsonObject {
    public:
        virtual ~IJsonObject() = default;

        [[nodiscard]]
        virtual std::string stringify() const = 0;

        virtual void parse(const IJsonParser &parser,
                           const std::string &string) = 0;

        [[nodiscard]]
        virtual JsonType getType() const = 0;

        [[nodiscard]]
        virtual std::string getName() const = 0;
    };
}
