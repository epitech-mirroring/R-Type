/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef COMPONENTFACTORY_HPP
#define COMPONENTFACTORY_HPP

#include <functional>
#include "common/IComponent.hpp"
#include "common/components/AComponent.hpp"
#include "common/json/JsonObject.hpp"


class ComponentFactory {
public:
    using Constructor = std::function<IComponent *(
        IObject *, const json::JsonObject *)>;

    template<typename T>
    static void registerComponent(const std::string &typeName) {
        registry()[typeName] = [
                ](IObject *owner,
                  const json::JsonObject *data) -> IComponent *{
                    auto comp = construct<T>(owner, data);
                    if (data->contains("data") && std::is_base_of_v<AComponent, T>) {
                        const auto *customData = data->getValue<
                            json::IJsonObject>("data");
                        dynamic_cast<AComponent *>(comp)->deserialize(customData);
                    }
                    return comp;
                };
    }

    [[nodiscard]]
    static IComponent *create(const std::string &typeName,
                              IObject *owner,
                              const json::JsonObject *data);

private:
    static std::unordered_map<std::string, Constructor> &registry();

    template<typename T>
    static IComponent *construct(IObject *owner,
                                 const json::JsonObject *data) {
        return new T(owner, data);
    }
};


#define REGISTER_COMPONENT(name) \
    static_assert(IsValidComponent<name>::value, "Check documentation for valid components"); \
    ComponentFactory::registerComponent<name>(#name)


#endif //COMPONENTFACTORY_HPP
