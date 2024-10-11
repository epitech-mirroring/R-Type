/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTO.hpp
*/

#ifndef IDTO_HPP
#define IDTO_HPP

#include <vector>

class IDTO {
public:
    virtual ~IDTO() = default;
    virtual std::vector<char> serialize() = 0;
    virtual void deserialize(std::vector<char> &data) = 0;
    virtual IDTO *clone() = 0;
};

#endif //IDTO_HPP
