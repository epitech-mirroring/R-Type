/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP
#include "IJsonParser.hpp"


namespace json {
    class JsonParser final : public IJsonParser {
    public:
        JsonParser() = default;

        ~JsonParser() override = default;

        [[nodiscard]]
        std::function<IJsonObject *(const std::string &)> getParser(
            const std::string &obj, const std::string &key) const override;

        [[nodiscard]] IJsonObject *parse(const std::string &string) const override;

        [[nodiscard]] std::size_t findContextEnd(const std::string &string,
                                                 std::size_t start,
                                                 bool skipToColon = true) const override;

        [[nodiscard]] std::size_t findContextStart(const std::string &string,
                                                   std::size_t start) const override;

        [[nodiscard]] std::string findKey(const std::string &string,
                                          std::size_t start) const override;

        [[nodiscard]] std::string cleanString(const std::string &string) const override;
    };
}


#endif //JSONPARSER_HPP
