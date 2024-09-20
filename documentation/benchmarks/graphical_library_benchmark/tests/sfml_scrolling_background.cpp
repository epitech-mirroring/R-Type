#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>

int main() {
    // Create a window for rendering
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Scrolling Background");

    // Load the background texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("tests/sprite.png")) {
        std::cerr << "Error loading background texture!" << std::endl;
        return -1;
    }

    // Create two sprites for the scrolling background
    sf::Sprite background1(backgroundTexture);
    sf::Sprite background2(backgroundTexture);

    // Place the second sprite right after the first one to create a continuous loop
    background2.setPosition(backgroundTexture.getSize().x, 0);

    float scrollSpeed = 200.0f;  // Pixels per second
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Calculate the elapsed time since last frame
        sf::Time elapsed = clock.restart();

        // Move the background sprites
        float distance = scrollSpeed * elapsed.asSeconds();
        background1.move(-distance, 0);
        background2.move(-distance, 0);

        // Reset position if the first background has scrolled off-screen
        if (background1.getPosition().x + backgroundTexture.getSize().x < 0) {
            background1.setPosition(background2.getPosition().x + backgroundTexture.getSize().x, 0);
        }
        if (background2.getPosition().x + backgroundTexture.getSize().x < 0) {
            background2.setPosition(background1.getPosition().x + backgroundTexture.getSize().x, 0);
        }

        // Render
        window.clear();
        window.draw(background1);
        window.draw(background2);
        window.display();

        // Output frame time
        std::cout << "Frame time: " << elapsed.asMilliseconds() << " ms" << std::endl;
    }

    return 0;
}
