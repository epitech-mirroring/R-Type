/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** EventData
*/

#ifndef EVENTDATA_HPP
#define EVENTDATA_HPP

#include <functional>

/**
 * @brief Structure to hold event data
 * @param name std::string, name of the event
 * @param timestamp time_t, timestamp of the event
 * @param data void *, data of the event (can be anything)
 * @note This structure is used to pass data to the event consumers
 */
struct EventData {
    std::string name;
    time_t timestamp;
    void *data;
};

/**
 * @brief Event consumer function type
 *
 * @param EventData_t * structure containing the event data
 * @note This function type is used to define the event consumers
 */
using EventConsumer = std::function<void (const EventData &)>;

#endif // EVENTDATA_HPP
