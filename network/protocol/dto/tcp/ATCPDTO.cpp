/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#include "ATCPDTO.hpp"


ATCPDTO::ATCPDTO(const int client_id)
    : _client_id(client_id)
{
}

std::vector<char> ATCPDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<int>(this->_client_id);
    data += this->serializeTCP();
    return data;
}

void ATCPDTO::deserialize(std::vector<char> &data)
{
    this->_client_id = BinaryConversion::consume<int>(data);
    this->deserializeTCP(data);
}

void ATCPDTO::setClientId(const int client_id)
{
    this->_client_id = client_id;
}

int ATCPDTO::getClientId() const
{
    return this->_client_id;
}
