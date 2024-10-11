/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** UIText.hpp
**/

#ifndef UITEXT_HPP
#define UITEXT_HPP

#include "AGraphicsComponent.hpp"

/**
 * @class UIText
 * @brief A class for rendering text as a graphical component.
 * @details UIText handles rendering of text on the screen, with customizable font, size, and color options.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane NOURRY
 */
class UIText : public AGraphicsComponent {
public:
    /**
     * @brief Constructor for the UIText class.
     * @param owner The owner of the component, of type IObject*.
     * @param textStr The string to display, as a const char*.
     * @param size The font size of the text.
     * @param color The color of the text, as an sf::Color object.
     * @param fontPath The file path to the font, with a default of "default".
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    UIText(IObject* owner, const char *textStr, unsigned int size, sf::Color color, const char *fontPath = "default");

    /**
     * @brief Destructor for the UIText class.
     * @details Cleans up and releases resources used by the UIText.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    ~UIText() = default;

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
     * @param textStr The string to display, as a const char*.
     * @details This method sets the text to display on the screen.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    void setText(const char *textStr);

    /**
     * @brief Sets the font to use for the text.
     * @param fontPath The file path to the font, as a const char*.
     * @details This method sets the font to use for rendering the text on the screen.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    void setFont(const char *fontPath);

    /**
     * @brief Finds the default font path for the current OS.
     * @return The default font path as a const char*.
     * @details This method finds the default font path for the current operating system.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    static const char *findDefaultFontPath();

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

    /**
     * @class Meta
     * @brief The metaclass for the UIText class.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane NOURRY
     */
    class Meta : public AMeta
    {
    public:
        Meta(); //< Constructor for the Meta class.
    };

private:
    sf::Text text; /**< The text object to render. */
    sf::Font font; /**< The font object to use for rendering the text. */
    const char *textString; /**< The string to display. */
    const char *fontPath; /**< The file path to the font. */
    unsigned int fontSize; /**< The font size to use. */
    sf::Color color; /**< The color of the text. */
};

#endif //UITEXT_HPP
