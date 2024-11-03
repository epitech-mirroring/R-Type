/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** TCPDTO
*/

#include "TCPCreateUDPEndpointDTO.hpp"

#include <utility>

TCPCreateUDPEndpointDTO::TCPCreateUDPEndpointDTO(asio::ip::udp::endpoint endpoint)
    :_endpoint(std::move(endpoint))
{
}

TCPCreateUDPEndpointDTO::TCPCreateUDPEndpointDTO() : _endpoint(asio::ip::udp::endpoint())
{
}

IDTO *TCPCreateUDPEndpointDTO::clone()
{
    return new TCPCreateUDPEndpointDTO();
}

std::vector<char> TCPCreateUDPEndpointDTO::serialize()
{
    std::vector<char> data = BinaryConversion::convert<asio::ip::udp::endpoint>(_endpoint);
    return data;
}

void TCPCreateUDPEndpointDTO::deserialize(std::vector<char> &data)
{
    this->_endpoint = BinaryConversion::consume<asio::ip::udp::endpoint>(data);
}

void TCPCreateUDPEndpointDTO::setEndpoint(asio::ip::udp::endpoint endpoint)
{
    this->_endpoint = std::move(endpoint);
}

[[nodiscard]] asio::ip::udp::endpoint TCPCreateUDPEndpointDTO::getEndpoint() const
{
    return this->_endpoint;
}
