/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef JSONNULL_HPP
#define JSONNULL_HPP
#include "IJsonPrimitiveObject.hpp"

namespace json {
    class JsonNull final : public IJsonPrimitiveObject<std::nullptr_t> {
    protected:
        std::string _name;

    public:
        explicit JsonNull(std::string name = "") noexcept;

        ~JsonNull() override = default;

        [[nodiscard]] std::string stringify() const override;

        void parse(const IJsonParser &parser, const std::string &string) override;

        [[nodiscard]] JsonType getType() const override;

        [[nodiscard]] std::string getName() const override;

        [[nodiscard]] std::nullptr_t getValue() const override;

        void setValue(const std::nullptr_t &value) override;

        explicit operator std::nullptr_t() const override;
    };
}

#endif //JSONNULL_HPP
