/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#pragma once
#include <cstddef>
#include <vector>
#include "IJsonObject.hpp"

namespace json {
    template<typename T>
    class JsonArray final : public IJsonObject {
    protected:
        std::string _name;
        std::vector<T *> _values;

    public:
        explicit JsonArray(std::string name = "root");

        ~JsonArray() override;

        void add(T *value);

        void remove(std::size_t index);

        [[nodiscard]]
        std::size_t size() const;

        [[nodiscard]]
        T *getValue(const std::size_t &index) const;

        [[nodiscard]]
        std::vector<T *> getValues() const;

        [[nodiscard]]
        std::string getName() const override;

        [[nodiscard]]
        std::string stringify() const override;

        void parse(const IJsonParser &parser,
                   const std::string &string) override;

        [[nodiscard]]
        JsonType getType() const override;

        explicit operator std::vector<T *>() const;

        T *operator[](const std::size_t &index) const;

        T *at(const std::size_t &index) const;
    };
}
