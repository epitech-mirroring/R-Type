/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#pragma once
#include <string>
#include <unordered_map>
#include "IJsonObject.hpp"

namespace json {
    class JsonObject final : public IJsonObject {
    protected:
        std::string _name;
        std::unordered_map<std::string, IJsonObject *> _objects;

    public:
        explicit JsonObject(std::string name = "root");

        ~JsonObject() override;

        void remove(const std::string &name);

        [[nodiscard]]
        std::string getName() const override;

        [[nodiscard]]
        std::string stringify() const override;

        void parse(const IJsonParser &parser,
                   const std::string &string) override;

        [[nodiscard]]
        JsonType getType() const override;

        template<typename T>
        T *getValue(const std::string &key) const {
            static_assert(std::is_base_of_v<IJsonObject, T>,
                          "T must inherit from IJsonObject");
            if (_objects.find(key) == _objects.end()) {
                return nullptr;
            }
            return dynamic_cast<T *>(_objects.at(key));
        }

        void add(IJsonObject *value);

        void setValue(const std::string &key, IJsonObject *value);

        [[nodiscard]]
        bool contains(const std::string &key) const;
    };
}
