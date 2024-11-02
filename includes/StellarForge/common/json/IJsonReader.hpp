/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef IJSONREADER_HPP
#define IJSONREADER_HPP
#include <iostream>
#include <sstream>

#include "IJsonObject.hpp"

namespace json {
    class IJsonReader {
    public:
        virtual ~IJsonReader() = default;

        IJsonObject *operator<<(std::istream &input) const {
            return this->read(input);
        }

        IJsonObject *operator<<(const char *input) const {
            std::istringstream stream(input);
            return this->read(stream);
        }

        [[nodiscard]]
        virtual IJsonObject *read(std::istream &input) const = 0;
    };
}

#endif //IJSONREADER_HPP
