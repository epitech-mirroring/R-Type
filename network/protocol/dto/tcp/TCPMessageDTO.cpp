/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/


#include "TCPMessageDTO.hpp"


TCPMessageDTO::TCPMessageDTO()
    : ATCPDTO(-1), _type(MessageType::NO_MESSAGE_TYPE)
{
}

TCPMessageDTO::TCPMessageDTO(const int client_id, MessageType type)
    : ATCPDTO(client_id), _type(type)
{
}

IDTO *TCPMessageDTO::clone()
{
    return new TCPMessageDTO();
}

std::vector<char> TCPMessageDTO::serializeTCP()
{
    std::vector<char> data = BinaryConversion::convert<MessageType>(this->_type);
    return data;
}

void TCPMessageDTO::deserializeTCP(std::vector<char> &data)
{
    this->_type = BinaryConversion::consume<MessageType>(data);
}

void TCPMessageDTO::setType(const MessageType type)
{
    this->_type = type;
}

[[nodiscard]] MessageType TCPMessageDTO::getType() const
{
    return this->_type;
}
