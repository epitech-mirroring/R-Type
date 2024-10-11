/*
** EPITECH PROJECT, 2024
** R-Type-Reborn
** File description:
** Background.cpp
*/

#include <ctime>
#include "StellarForge/common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/common/components/Transform.hpp"

class Background : public CPPMonoBehaviour {
    public:
        Background() {
            start = clock();
        }
        ~Background() = default;

        Transform *getOwnerTransform() {
            for (auto &component : this->getOwner()->getComponents()) {
                if (component->getMeta().getName() == "Transform") {
                    return dynamic_cast<Transform *>(component);
                }
            }
            return nullptr;
        }
        void update() override {
            clock_t actual = clock();
            if ((actual - start) / CLOCKS_PER_SEC >= 0.10f / speed) {
                start = actual;
                auto *transform = getOwnerTransform();
                transform->setPosition(transform->getPosition().x - 1, transform->getPosition().y);
                if (transform->getPosition().x <= -1920)
                    transform->setPosition(0, transform->getPosition().y);
            }
        }
    private:
        float speed = 1.00f;
        clock_t start;
};
