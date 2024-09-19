#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>

int main() {
    // Create a window for rendering
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Benchmark");

    // Load a texture from a file
    sf::Texture texture;
    if (!texture.loadFromFile("tests/sprite.png")) {
        std::cerr << "Error loading sprite texture!" << std::endl;
        return -1;
    }

    // Create 1000 sprites using the texture
    std::vector<sf::Sprite> sprites(1000);
    for (auto& sprite : sprites) {
        sprite.setTexture(texture);
        sprite.setPosition(rand() % 800, rand() % 600);  // Randomize position
    }

    // Create a clock to measure frame time
    sf::Clock clock;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        // Draw all 1000 sprites
        for (const auto& sprite : sprites) {
            window.draw(sprite);
        }

        // Display the rendered frame
        window.display();

        // Measure and output the frame time
        sf::Time elapsed = clock.restart();
        std::cout << "Frame time: " << elapsed.asMilliseconds() << " ms" << std::endl;
    }

    return 0;
}
