/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Packets
*/

#ifndef CREATETCPPACKET_HPP
#define CREATETCPPACKET_HPP
#include <vector>

#define PACKET_MAX_SIZE 1024
#define PACKET_HEADER_SIZE 8

/**
 * @class TCPPacket
 * @brief Create a TCP packet with a payload content
 * @details This class is used to create a TCP packet with a payload content
 * @version 0.1.0
 * @since 0.1.0
 * @author Simon GANIER-LOMBARD
 */
class TCPPacket {
public:
    /**
     * @brief Default constructor
     * @details This constructor initializes the TCPPacket with a message
     * @param message std::string, the message
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    TCPPacket();

    /**
     * @brief Default destructor
     * @details This destructor is defaulted
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    ~TCPPacket() = default;

    /**
     * @brief Set the payload content
     * @details This method sets the payload content of the TCP packet
     * @param data std::vector<char>, the data to be set as payload
     * @param sizeOfData int, the size of the data
     * @return bool, true if the payload is set successfully, false otherwise
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    bool setPayloadContent(const std::vector<char> &data, int sizeOfData);

    /**
     * @brief Get the payload content
     * @details This method returns the payload content of the TCP packet
     * @return std::vector<char>, the payload content
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    std::vector<char> getPayloadContent();

    /**
     * @brief Get the packet
     * @details This method returns the entire TCP packet
     * @return std::vector<char>, the TCP packet
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    std::vector<char> getPacket();

    /**
     * @brief Get the packet size
     * @details This method returns the size of the TCP packet
     * @return int, the size of the TCP packet
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    int getPacketSize();

    /**
     * @brief Set the packet
     * @details This method sets the entire TCP packet
     * @param packet std::vector<char>, the TCP packet to be set
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    void setPacket(const std::vector<char> &packet);

private:
    /**
     * @brief The TCP packet
     * @details This member variable holds the entire TCP packet
     * @version 0.1.0
     * @since 0.1.0
     * @author Simon GANIER-LOMBARD
     */
    std::vector<char> _packet;
};

#endif //CREATETCPPACKET_HPP
