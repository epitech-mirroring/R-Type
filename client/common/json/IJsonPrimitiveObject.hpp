/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef IJSONPRIMITIVEOBJECT_HPP
#define IJSONPRIMITIVEOBJECT_HPP
#include "IJsonObject.hpp"

namespace json {
    template<typename T>
    class IJsonPrimitiveObject : public IJsonObject {
    public:
        ~IJsonPrimitiveObject() override = default;

        virtual T getValue() const = 0;

        virtual void setValue(const T &value) = 0;

        virtual explicit operator T() const = 0;
    };
}

#endif //IJSONPRIMITIVEOBJECT_HPP
