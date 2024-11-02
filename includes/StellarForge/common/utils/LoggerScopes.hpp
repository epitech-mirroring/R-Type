/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef LOGGERSCOPESE_HPP
#define LOGGERSCOPESE_HPP
#include <iostream>
#include <string>
#include <unordered_map>

class LoggerScopes {
    static LoggerScopes *INSTANCE;

protected:
    std::unordered_map<std::string, std::pair<std::ostream &, std::ostream &> > _scopes;

public:
    LoggerScopes() = default;

    ~LoggerScopes() = default;

    static LoggerScopes *getInstance();

    void addScope(const std::string &scope, std::ostream &output = std::cout,
                  std::ostream &error = std::cerr);

    [[nodiscard]]
    std::pair<std::ostream &, std::ostream &> &getScope(const std::string &scope);

    void removeScope(const std::string &scope);

    [[nodiscard]]
    bool hasScope(const std::string &scope) const;
};

#endif //LOGGERSCOPESE_HPP
