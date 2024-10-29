/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonPrettyWriter.hpp"
using namespace json;

JsonPrettyWriter::JsonPrettyWriter(IJsonObject const *root,
                                   std::size_t indent) : root(root), indent(indent) {
}

std::ostream &JsonPrettyWriter::write(std::ostream &output) const {
    const std::string str = root->stringify();
    int indent = 0;
    for (const char character: str) {
        if (character == '{' || character == '[') {
            output << character << '\n';
            indent++;
            for (int j = 0; j < indent * this->indent; j++) {
                output << " ";
            }
        } else if (character == '}' || character == ']') {
            output << '\n';
            indent--;
            for (int j = 0; j < indent * this->indent; j++) {
                output << " ";
            }
            output << character;
        } else if (character == ',') {
            output << character << '\n';
            for (int j = 0; j < indent * this->indent; j++) {
                output << " ";
            }
        } else if (character == ':') {
            output << character << " ";
        } else {
            output << character;
        }
    }
    return output;
}
