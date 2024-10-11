/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** IDTODecoder.hpp
*/

#ifndef IDTODECODER_HPP
#define IDTODECODER_HPP

#include <vector>
#include "IDTO.hpp"

class IDTODecoder {
public:
	virtual ~IDTODecoder() = default;
    [[nodiscard]] virtual IDTO *decode(std::vector<char> &data) const = 0;
};

#endif //IDTODECODER_HPP
