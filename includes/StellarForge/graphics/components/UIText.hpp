/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** UIText.hpp
**/

#ifndef UITEXT_HPP
#define UITEXT_HPP
#include "IGraphicsComponent.hpp"
#include "common/components/AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"

/**
 * @class UIText
 * @brief A class for rendering text as a graphical component.
 * @details UIText handles rendering of text on the screen, with customizable font, size, and color options.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class UIText final : public AComponent, IGraphicsComponent {
public:
 /**
  * @brief Constructor for the UIText class.
  * @param owner The owner of the component, of type IObject*.
  * @param textStr The string to display, as a const char*.
  * @param size The font size of the text.
  * @param color The color of the text, as a sf::Color object.
  * @param fontPath The file path to the font, with a default of "default".
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 UIText(IObject *owner, std::string textStr, unsigned int size, sf::Color color,
        const std::string &fontPath = "default");

 UIText(IObject *owner, const json::JsonObject *data);

 /**
  * @brief Destructor for the UIText class.
  * @details Cleans up and releases resources used by the UIText.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 ~UIText() override = default;

 /**
  * @brief Renders the text on the screen using the provided window.
  * @param window A pointer to the sf::RenderWindow object used for rendering.
  * @details This method renders the text on the screen at the specified position using the provided window.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void render(sf::RenderWindow *window) override;

 /**
  * @brief Sets the text to display.
  * @param textStr The string to display, as a std::string.
  * @details This method sets the text to display on the screen.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setText(const std::string &textStr);

 /**
  * @brief Sets the font to use for the text.
  * @param fontPath The file path to the font, as a std::string.
  * @details This method sets the font to use for rendering the text on the screen.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setFont(const std::string &fontPath);

 /**
  * @brief Finds the default font path for the current OS.
  * @return The default font path as a const char*.
  * @details This method finds the default font path for the current operating system.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 static std::string findDefaultFontPath();

 /**
  * @brief Sets the font size for the text.
  * @param size The font size to use.
  * @details This method sets the font size to use for rendering the text on the screen.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setSize(unsigned int size);

 /**
  * @brief Sets the color of the text.
  * @param color The color of the text, as an sf::Color object.
  * @details This method sets the color of the text to use for rendering on the screen.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 void setColor(sf::Color color);

 /**
  * @brief Gets the size of the text on the screen.
  * @return The size of the text as a glm::vec2.
  * @details This method returns the size of the text on the screen as a glm::vec2, where x is the width and y is the height.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 glm::vec2 getSize() override;

 void runComponent() override;

 /**
  * @class Meta
  * @brief The metaclass for the UIText class.
  * @version v0.1.0
  * @since v0.1.0
  * @author Aubane NOURRY
  */
 class Meta final : public IMeta {
 protected:
  UIText *_owner;
  InvisibleFieldGroup _fieldGroup;

 public:
  explicit Meta(UIText *owner); //< Constructor for the Meta class.

  [[nodiscard]] std::string getName() const override;

  [[nodiscard]] std::string getDescription() const override;

  [[nodiscard]] bool isUnique() const override;

  [[nodiscard]] bool canBeRemoved() const override;

  [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
 };

 [[nodiscard]] json::IJsonObject *serializeData() override;

 void deserialize(const json::IJsonObject *data) override;

 [[nodiscard]] UIText *clone(IObject *owner) const override;

private:
 sf::Text text; /**< The text object to render. */
 sf::Font font; /**< The font object to use for rendering the text. */
 std::string textString; /**< The string to display. */
 std::string fontPath; /**< The file path to the font. */
 unsigned int fontSize; /**< The font size to use. */
 sf::Color color; /**< The color of the text. */
};

#endif //UITEXT_HPP
