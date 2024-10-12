/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef JSONPRETTYWRITER_HPP
#define JSONPRETTYWRITER_HPP
#include "IJsonObject.hpp"
#include "IJsonWriter.hpp"


namespace json {
    class JsonPrettyWriter final : public IJsonWriter {
    protected:
        IJsonObject const *root;
        std::size_t indent;

    public:
        JsonPrettyWriter(IJsonObject const *root, std::size_t indent = 2);

        ~JsonPrettyWriter() override = default;

        std::ostream &write(std::ostream &output) const override;
    };
}

#endif //JSONPRETTYWRITER_HPP
