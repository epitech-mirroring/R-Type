/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef IJSONWRITER_HPP
#define IJSONWRITER_HPP
#ifndef __APPLE__
#include <iostream>
#endif

namespace json {
    class IJsonWriter {
    public:
        virtual ~IJsonWriter() = default;

        friend std::ostream &operator<<(std::ostream &output,
                                        const IJsonWriter &obj) {
            return obj.write(output);
        }

        virtual std::ostream &write(std::ostream &output) const = 0;
    };
}

#endif //IJSONWRITER_HPP
