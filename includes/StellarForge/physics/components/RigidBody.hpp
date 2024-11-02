/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** Author: landry GIGANT
*/

#ifndef STELLARFORGE_RIGIDBODY_HPP
#define STELLARFORGE_RIGIDBODY_HPP

#include "common/components/AComponent.hpp"
#include <glm/vec3.hpp>

#include "common/fields/groups/InvisibleFieldGroup.hpp"

/**
 * @class RigidBody
 * @brief Represents a rigid body component in the physics system.
 * @version v0.1.0
 * @since v0.1.0
 * @author landry GIGANT
 */
class RigidBody final : public AComponent {
 glm::vec3 _velocity; ///< The velocity of the rigid body.
 glm::vec3 _acceleration; ///< The acceleration of the rigid body.
 float _terminalVelocity; ///< The terminal velocity of the rigid body.
 float _drag; ///< The drag coefficient of the rigid body.

public:
 /**
  * @class RigidBody::Meta
  * @brief Metadata class for the RigidBody component.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 class Meta final : public IMeta {
 protected:
  RigidBody *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  explicit Meta(RigidBody *owner);

  ~Meta() override = default;

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 /**
  * @brief Constructor for RigidBody.
  * @param owner Pointer to the owner object.
  * @param data The data to initialize the component with.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 explicit RigidBody(IObject *owner, const json::JsonObject *data = nullptr);

 /**
  * @brief Destructor for RigidBody.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 ~RigidBody() override = default;

 /**
  * @brief Applies movement to the rigid body based on its velocity and the elapsed time.
  * @param deltaTime The elapsed time since the last update.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 void applyMovement(float deltaTime);

 /**
  * @brief Applies drag to the rigid body based on its drag coefficient and the elapsed time.
  * @param deltaTime The elapsed time since the last update.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 void applyDrag(float deltaTime);

 /**
  * @brief Applies a force to the rigid body based on its acceleration and the elapsed time.
  * @param deltaTime The elapsed time since the last update.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 void applyForce(float deltaTime);

 /**
  * @brief Applies an impulse to the rigid body.
  * @param impulse The impulse vector to be applied.
  * @version v0.1.0
  * @since v0.1.0
  * @author landry GIGANT
  */
 void applyImpulse(const glm::vec3 &impulse);

 void runComponent() override;

 void deserialize(const json::IJsonObject *data) override;

 [[nodiscard]] RigidBody *clone(IObject *owner) const override;

protected:
 [[nodiscard]] json::IJsonObject *serializeData() override;
};

#endif //STELLARFORGE_RIGIDBODY_HPP
