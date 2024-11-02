/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef IJSONPARSER_HPP
#define IJSONPARSER_HPP
#include <functional>
#include <string>

#include "IJsonObject.hpp"

namespace json {
    class IJsonParser {
    public:
        virtual ~IJsonParser() = default;

        [[nodiscard]]
        virtual std::function<IJsonObject *(const std::string &)> getParser(
            const std::string &obj, const std::string &key) const = 0;

        [[nodiscard]] virtual IJsonObject *parse(const std::string &string) const = 0;

        [[nodiscard]] virtual std::size_t findContextEnd(
            const std::string &string,
            std::size_t start,
            bool skipToColon = true) const = 0;

        [[nodiscard]]
        virtual std::size_t findContextStart(
            const std::string &string,
            std::size_t start) const = 0;

        [[nodiscard]]
        virtual std::string
        findKey(const std::string &string, std::size_t start) const = 0;

        [[nodiscard]]
        virtual std::string cleanString(const std::string &string) const = 0;
    };
}

#endif //IJSONPARSER_HPP
