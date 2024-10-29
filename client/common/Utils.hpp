/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef UTILS_HPP
#define UTILS_HPP
#if defined(__linux__) || defined(__APPLE__)
#include <cxxabi.h>

template<typename T>
std::string get_typename([[maybe_unused]] T *object) {
    return abi::__cxa_demangle(typeid(*object).name(), nullptr, nullptr, nullptr);
}

#else
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#include <dbghelp.h>

template<typename T>
auto get_typename() {
    auto type_info = typeid(T);
    char *name = nullptr;
    auto status = UnDecorateSymbolName(type_info.name(), name, 0, 0);
    std::string result;
    if (status == 0) {
        result = std::string(type_info.name());
    }
    result = std::string(name);
    if (result.find("class ") != std::string::npos) {
        result.erase(0, 6);
    } else if (result.find("struct ") != std::string::npos) {
        result.erase(0, 7);
    }
    return result;
}
#endif

template<typename T>
std::string get_typename([[maybe_unused]] T *object) {
    std::string name = typeid(*object).name();
    if (name.find("class ") != std::string::npos) {
        name.erase(0, 6);
    } else if (name.find("struct ") != std::string::npos) {
        name.erase(0, 7);
    }
    return name;
}

#endif

#endif //UTILS_HPP
