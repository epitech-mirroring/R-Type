/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef JSONREADER_HPP
#define JSONREADER_HPP
#include "IJsonReader.hpp"
#include "IJsonParser.hpp"

namespace json {
    class JsonReader final : public IJsonReader {
    protected:
        const IJsonParser *parser;

    public:
        explicit JsonReader(const IJsonParser *parser);

        ~JsonReader() override = default;

        [[nodiscard]]
        IJsonObject *read(std::istream &input) const override;
    };
}

#endif //JSONREADER_HPP
