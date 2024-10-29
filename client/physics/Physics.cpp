/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "Physics.hpp"
#include <algorithm>
#include <glm/geometric.hpp>

void Physics::Movement::applyMovement(Vector3 &pos, const Vector3 &vel,
                                      const float deltaTime) {
    pos += vel * deltaTime;
}

void Physics::Movement::applyMovement(Vector3 &pos, Vector3 &vel,
                                      const Vector3 &acc,
                                      const float deltaTime) {
    pos += vel * deltaTime + 0.5f * acc * deltaTime * deltaTime;

    vel += acc * deltaTime;
}

void Physics::Movement::applyMovement(Vector3 &pos, Vector3 &vel,
                                      const Vector3 &acc,
                                      const float terminalVelocity,
                                      const float deltaTime) {
    pos += vel * deltaTime + 0.5f * acc * deltaTime * deltaTime;

    vel += acc * deltaTime;

    const float distance = length(vel);

    if (distance > terminalVelocity) {
        vel *= terminalVelocity / distance;
    }
}

void Physics::Movement::applyDrag(Vector3 &vel, const float drag,
                                  const float deltaTime) {
    const float distance = length(vel);

    if (distance > drag * deltaTime) {
        vel -= vel * drag * deltaTime / distance;
    } else {
        vel = {0, 0, 0};
    }
}

void Physics::Movement::applyForce(Vector3 &vel, const Vector3 &force,
                                   const float deltaTime) {
    vel += force * deltaTime;
}

void Physics::Movement::applyImpulse(Vector3 &vel, const Vector3 &impulse) {
    vel += impulse;
}

bool Physics::Collision::boxCollideBox(const Box &box1, const Box &box2)
{
    return (std::min(box1.position.x, box1.position.x + box1.size.x) <= std::max(box2.position.x, box2.position.x + box2.size.x) &&
            std::max(box1.position.x, box1.position.x + box1.size.x) >= std::min(box2.position.x, box2.position.x + box2.size.x) &&
            std::min(box1.position.y, box1.position.y + box1.size.y) <= std::max(box2.position.y, box2.position.y + box2.size.y) &&
            std::max(box1.position.y, box1.position.y + box1.size.y) >= std::min(box2.position.y, box2.position.y + box2.size.y) &&
            std::min(box1.position.z, box1.position.z + box1.size.z) <= std::max(box2.position.z, box2.position.z + box2.size.z) &&
            std::max(box1.position.z, box1.position.z + box1.size.z) >= std::min(box2.position.z, box2.position.z + box2.size.z));
}

bool Physics::Collision::sphereCollideSphere(const Sphere &sphere1, const Sphere &sphere2) {
    return glm::distance(sphere1.position, sphere2.position) < sphere1.radius + sphere2.radius;
}

bool Physics::Collision::boxCollideSphere(const Box &box, const Sphere &sphere) {
    const Vector3 closestPoint = glm::vec3(
            glm::clamp(sphere.position.x, std::min(box.position.x, box.position.x + box.size.x),
                       std::max(box.position.x, box.position.x + box.size.x)),
            glm::clamp(sphere.position.y, std::min(box.position.y, box.position.y + box.size.y),
                       std::max(box.position.y, box.position.y + box.size.y)),
            glm::clamp(sphere.position.z, std::min(box.position.z, box.position.z + box.size.z),
                       std::max(box.position.z, box.position.z + box.size.z))
    );
    return glm::distance(sphere.position, closestPoint) < sphere.radius;
}

bool Physics::Collision::sphereCollideBox(const Sphere &sphere, const Box &box) {
    return boxCollideSphere(box, sphere);
}
