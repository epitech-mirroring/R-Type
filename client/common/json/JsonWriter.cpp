/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonWriter.hpp"
using namespace json;

JsonWriter::JsonWriter(IJsonObject const *root) : root(root) {
}

std::ostream &JsonWriter::write(std::ostream &output) const {
    output << root->stringify();
    return output;
}
