/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** Sprite.hpp
**/

#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "IGraphicsComponent.hpp"
#include "common/components/AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"

/**
 * @class Sprite
 * @brief A graphics component that renders a sprite on the screen.
 * @details The Sprite class is responsible for rendering a sprite on the screen using an sf::RenderWindow object.
 *          It loads the texture from a file path and renders it at a specified position on the screen.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class Sprite final : public AComponent, IGraphicsComponent {
public:
 /**
  * @brief Constructor for the Sprite class.
  * @param owner The owner of the component.
  * @param path The file path to the sprite image.
  * @details This constructor initializes the Sprite with the specified file path.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 Sprite(IObject *owner, const std::string &path);

 Sprite(IObject *owner, const json::JsonObject *data);

 /**
  * @brief Destructor for the Sprite class.
  * @details Cleans up and releases any resources used by the Sprite.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~Sprite() override = default;

 /**
  * @brief Renders the sprite on the screen using the provided window.
  * @param window A pointer to the sf::RenderWindow object used for rendering.
  * @details This method renders the sprite on the screen at the specified position using the provided window.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void render(sf::RenderWindow *window) override;

 /**
  * @brief Sets the texture of the sprite to the specified file path.
  * @param path The file path to the new sprite image.
  * @details This method loads the texture from the specified file path and sets it as the new sprite texture.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setTexture(const std::string &path);

 /**
  * @brief Gets the size of the sprite on the screen.
  * @return The size of the sprite as a glm::vec2.
  * @details This method returns the size of the sprite on the screen as a glm::vec2, where x is the width and y is the height.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 glm::vec2 getSize() override;

 void runComponent() override;

 [[nodiscard]] std::string getPath() const;

 /**
  * @class Meta
  * @brief The metaclass for the Sprite class
  * @version v0.1.0
  * @since v0.1.0
  * @authors Aubane NOURRY, Axel ECKENBERG
  */
 class Meta final : public IMeta {
 protected:
  Sprite *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  /**
   * @brief The constructor of the Meta class for the Sprite class
   * @version v0.1.0
   * @since v0.1.0
   * @author Aubane NOURRY
   */
  explicit Meta(Sprite *owner);

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 [[nodiscard]] json::IJsonObject *serializeData() override;

 void deserialize(const json::IJsonObject *data) override;

 [[nodiscard]] Sprite *clone(IObject *owner) const override;

private:
 sf::Texture texture; /**< The texture of the sprite. */
 sf::Sprite sprite; /**< The sprite object to render. */
 std::string path; /**< The file path to the sprite image. */
};

#endif //SPRITE_HPP
