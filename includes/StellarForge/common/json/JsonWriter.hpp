/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef JSONWRITER_HPP
#define JSONWRITER_HPP
#include "IJsonObject.hpp"
#include "IJsonWriter.hpp"

namespace json {
    class JsonWriter final : public IJsonWriter {
    protected:
        IJsonObject const *root;

    public:
        explicit JsonWriter(IJsonObject const *root);

        ~JsonWriter() override = default;

        std::ostream &write(std::ostream &output) const override;
    };
}


#endif //JSONWRITER_HPP
