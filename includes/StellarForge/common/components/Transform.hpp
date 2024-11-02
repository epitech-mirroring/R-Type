/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Transform.hpp
*/

#ifndef STELLARFORGE_TRANSFORM_HPP
#define STELLARFORGE_TRANSFORM_HPP

#include <glm/gtc/quaternion.hpp>
#include <glm/vec3.hpp>

#include "AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"
#include "common/factories/ComponentFactory.hpp"

using Vector3 = glm::vec3;

/**
 * @class Transform
 * @brief Represents the transformation (position, rotation, scale) of an object in 3D space.
 * @version v0.1.0
 * @since v0.1.0
 * @authors Landry GIGANT, Axel ECKENBERG
 */
class Transform final : public AComponent {
protected:
 Vector3 _position; ///< The position of the object in 3D space.
 glm::quat _rotation; ///< The rotation of the object represented as a quaternion.
 Vector3 _scale; ///< The scale of the object in 3D space.

public:
 /**
  * @class Transform::Meta
  * @brief Metadata class for the Transform component.
  * @version v0.1.0
  * @since v0.1.0
  */
 class Meta final : public IMeta {
 protected:
  Transform *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  /**
   * @brief Constructor for Transform::Meta.
   * Initializes the metadata with the name, description, and field groups.
   * @param
   * @version v0.1.0
   * @since v0.1.0
   */
  explicit Meta(Transform *owner);

  ~Meta() override = default;

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 /**
  * @brief Constructor for Transform.
  * @param owner Pointer to the owner object.
  * Initializes the Transform component with default position, rotation, and scale.
  * @param data Pointer to the JSON object containing the data.
  * @version v0.1.0
  * @since v0.1.0
  */
 explicit Transform(IObject *owner, const json::JsonObject *data = nullptr);

 /**
  * @brief Constructor for Transform.
  * @param owner Pointer to the owner object.
  * @param pos The initial position of the object.
  * @param rot The initial rotation of the object.
  * @param scale The initial scale of the object.
  * Initializes the Transform component with the given position, rotation, and scale.
  * @version v0.1.0
  * @since v0.1.0
  */
 Transform(IObject *owner, Vector3 pos, glm::quat rot, Vector3 scale);

 /**
  * @brief Gets the position of the object.
  * @return The position as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] Vector3 getPosition() const;

 /**
  * @brief Gets the rotation of the object.
  * @return The rotation as a quaternion.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] glm::quat getRotation() const;

 /**
  * @brief Gets the scale of the object.
  * @return The scale as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] Vector3 getScale() const;

 /**
  * @brief Gets the position of the object.
  * @return The position as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] Vector3 &getPosition();

 /**
  * @brief Gets the rotation of the object.
  * @return The rotation as a quaternion.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] glm::quat &getRotation();

 /**
  * @brief Gets the scale of the object.
  * @return The scale as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 [[nodiscard]] Vector3 &getScale();

 /**
  * @brief Sets the position of the object.
  * @param pos The new position as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 void setPosition(Vector3 pos);

 /**
  * @brief Translates the object by a given position.
  * @param pos The translation vector.
  * @version v0.1.0
  * @since v0.1.0
  */
 void translate(Vector3 pos);

 /**
  * @brief Sets the rotation of the object.
  * @param rot The new rotation as a quaternion.
  * @version v0.1.0
  * @since v0.1.0
  */
 void setRotation(glm::quat rot);

 /**
  * @brief Rotates the object around a given axis by a given angle.
  * @param axis The axis of rotation.
  * @param angle The angle of rotation in degrees.
  * @version v0.1.0
  * @since v0.1.0
  */
 void rotate(Vector3 axis, float angle);

 /**
  * @brief Sets the scale of the object.
  * @param scale The new scale as a Vector3.
  * @version v0.1.0
  * @since v0.1.0
  */
 void setScale(Vector3 scale);

 /**
  * @brief Scales the object by a given factor.
  * @param scale The scaling factor.
  * @version v0.1.0
  * @since v0.1.0
  */
 void scaleBy(Vector3 scale);

 void runComponent() override;

 [[nodiscard]] json::IJsonObject *serializeData() override;

 void deserialize(const json::IJsonObject *data) override;

 [[nodiscard]] Transform *clone(IObject *owner) const override;
};

#endif //STELLARFORGE_TRANSFORM_HPP
