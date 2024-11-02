/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#include "TCPSendIdDTO.hpp"

TCPSendIdDTO::TCPSendIdDTO(int client_id) : _client_id(client_id)
{
}

TCPSendIdDTO::TCPSendIdDTO() : _client_id(-1)
{
}

void TCPSendIdDTO::setID(int id)
{
    this->_client_id = id;
}

[[nodiscard]] int TCPSendIdDTO::getID() const
{
    return this->_client_id;
}

IDTO *TCPSendIdDTO::clone()
{
    return new TCPSendIdDTO();
}

std::vector<char> TCPSendIdDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_client_id);
    return data;
}

void TCPSendIdDTO::deserialize(std::vector<char> &data)
{
    this->_client_id = BinaryConversion::consume<int>(data);
}
