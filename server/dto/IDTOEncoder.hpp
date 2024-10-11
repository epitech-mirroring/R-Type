/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTOEncoder.hpp
*/

#ifndef IDTOENCODER_HPP
#define IDTOENCODER_HPP

#include "IDTO.hpp"
#include <vector>

class IDTOEncoder {
public:
    virtual ~IDTOEncoder() = default;
    [[nodiscard]] virtual std::vector<char> encode(IDTO &dto) const = 0;

};



#endif //IDTOENCODER_HPP
