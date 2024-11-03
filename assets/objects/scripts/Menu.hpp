/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Menu.hpp
*/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>

#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"
#include "StellarForge/Common/managers/ObjectManager.hpp"
#include "StellarForge/Common/managers/SceneManager.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"

#include <unordered_map>
#include <typeindex>
#include <vector>

class Menu final : public CPPMonoBehaviour {
public:
    Menu(IObject *owner, const json::JsonObject *data);
    ~Menu() override = default;

    void start() override;
    void update() override;

    void connect(const std::string &ipStr, int tcp_port, int udp_port);

    static bool endsWith(const std::string &str, const std::string &suffix);

    void resetMenu();

    static bool isValidPort(const std::string& port);
    static bool isValidIp(const std::string& ipStr);
    void tryConnect(const EventData &data);
    void startInput(const EventData &data);
    void stopInput(const EventData &data);

    IComponent *clone(IObject *owner) const override;
    void deserialize(const json::IJsonObject *data) override;
    void end() override;
    json::IJsonObject *serializeData() const override;

private:
    bool triedToConnect = false;
#ifdef _WIN32
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point actualTime;
#elif defined(__linux__)
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point actualTime;
#else
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point actualTime;
#endif
};

#endif //MENU_HPP
