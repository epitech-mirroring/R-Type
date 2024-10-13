/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#ifndef VIRTUALOBJECT_HPP
#define VIRTUALOBJECT_HPP
#include "IObject.hpp"

class VirtualObject final : public IObject {
protected:
    IObject *_parent;
    std::vector<IObject *> _children;
    std::vector<IComponent *> _components;
    IMeta *_meta;
    bool _active;

public:
    explicit VirtualObject(IMeta *meta);

    ~VirtualObject() override = default;

    [[nodiscard]] IObject *clone() const override;

    [[nodiscard]] std::vector<IComponent *> getComponents() const override;

    [[nodiscard]] std::vector<IObject *> getChildren() const override;

    [[nodiscard]] std::optional<IObject *> getParent() const override;

    void setParent(IObject *parent) override;

    void addChild(IObject *child) override;

    void removeChild(IObject *child) override;

    void addComponent(IComponent *component) override;

    void removeComponent(IComponent *component) override;

    void runObject() override;

    bool isActive() override;

    void setActive(bool active) override;

    [[nodiscard]] IMeta &getMeta() const override;

    class Meta final : public IMeta {
    protected:
        std::string name;

    public:
        explicit Meta(std::string name);

        ~Meta() override = default;

        [[nodiscard]] std::string getName() const override;
    };
};

#endif //VIRTUALOBJECT_HPP
