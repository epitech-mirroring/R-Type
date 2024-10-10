/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/


#ifndef IINTERNALMESSAGE_HPP
#define IINTERNALMESSAGE_HPP

#include <string>

class IInternalMessage {
public:
    virtual ~IInternalMessage() = default;

    [[nodiscard]] virtual std::string getMessage() const = 0;
    
};

#endif //IINTERNALMESSAGE_HPP
