/*
** EPITECH PROJECT, 2024
** Stellar-Forge
** File description:
** EventSystem
*/

#include "EventSystem.hpp"
#include <ctime>

EventSystem &EventSystem::getInstance() {
    static EventSystem instance;
    return instance;
}

EventSystem::EventSystem(): _listeners({}) {
}

EventSystem::~EventSystem() {
    for (auto &[_, listenerVector]: this->_listeners) {
        listenerVector.clear();
    }
    this->_listeners.clear();
}

UUID EventSystem::registerListener(const std::string &name,
                                   const EventConsumer &listener) {
    auto uuid = UUID();
    uuid.generateUuid();

    if (this->_listeners.find(name) == this->_listeners.end()) {
        this->_listeners[name] = std::vector<std::pair<UUID, EventConsumer>>();
    }
    this->_listeners[name].emplace_back(uuid, listener);
    return uuid;
}

bool EventSystem::unregisterListener(const UUID &uuid) {
    for (auto &[key, listenersVector]: this->_listeners) {
        for (int i = 0; i < listenersVector.size(); i++) {
            if (listenersVector[i].first == uuid) {
                listenersVector.erase(listenersVector.begin() + i);
                if (listenersVector.empty()) {
                    this->_listeners.erase(key);
                }
                return true;
            }
        }
    }
    return false;
}

bool EventSystem::triggerEvents(const std::string &eventName, void *data) {
    auto const eventData = EventData{eventName, time(nullptr), data};
    bool handled = false;

    if (this->_listeners.find(eventName) != this->_listeners.end()) {
        handled = this->_triggerEventFromEventName(eventName, eventData) || handled;
    }
    for (auto &[key, _]: this->_listeners) {
        std::size_t const found = key.find('*');
        if (found != std::string::npos) {
            std::string const name = key.substr(0, found);
            if (eventName.find(name) == 0) {
                handled = this->_triggerEventFromEventName(key, eventData) || handled;
            }
        }
    }
    return handled;
}

bool EventSystem::_triggerEventFromEventName(const std::string &eventName,
                                             const EventData &eventData) {
    bool handled = false;

    for (auto &[_, callback]: this->_listeners[eventName]) {
        callback(eventData);
        handled = true;
    }
    return handled;
}
