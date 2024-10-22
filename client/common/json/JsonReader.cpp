/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "JsonReader.hpp"
using namespace json;

JsonReader::JsonReader(const IJsonParser *parser) : parser(parser) {
}

IJsonObject *JsonReader::read(std::istream &input) const {
    const std::string str((std::istreambuf_iterator(input)),
                          std::istreambuf_iterator<char>());
    return parser->parse(str);
}
