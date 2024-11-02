/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Packets
*/

#include "TCPPacket.hpp"
#include <cstring>
#include <iostream>

TCPPacket::TCPPacket()
{
    _packet.resize(PACKET_MAX_SIZE);
}

bool TCPPacket::setPayloadContent(const std::vector<char> &data, const int sizeOfData)
{
    if (sizeOfData > PACKET_MAX_SIZE - PACKET_HEADER_SIZE) {
        return false;
    }
    const int size = sizeOfData;
    std::memcpy(_packet.data(), &size, sizeof(int));
    std::memcpy(_packet.data() + PACKET_HEADER_SIZE, data.data(), sizeOfData);
    return true;
}

std::vector<char> TCPPacket::getPayloadContent()
{
    int size = 0;
    std::memcpy(&size, _packet.data(), sizeof(int));
    std::vector<char> data(size);
    std::memcpy(data.data(), _packet.data() + PACKET_HEADER_SIZE, size);
    return data;
}

void TCPPacket::setPacket(const std::vector<char> &packet)
{
    _packet = packet;
}

int TCPPacket::getPacketSize()
{
    int size = 0;
    std::memcpy(&size, _packet.data(), sizeof(int));
    return size;
}

std::vector<char> TCPPacket::getPacket()
{
    return _packet;
}
