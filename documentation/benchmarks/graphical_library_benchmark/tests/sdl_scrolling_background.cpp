#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // Initialize SDL2 and SDL_image
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("SDL2 Scrolling Background", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create a renderer for the window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Load a PNG image as the background
    SDL_Texture* backgroundTexture = IMG_LoadTexture(renderer, "tests/sprite.png");
    if (!backgroundTexture) {
        std::cerr << "Failed to load background image! IMG_Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    // Get texture size
    int backgroundWidth, backgroundHeight;
    SDL_QueryTexture(backgroundTexture, NULL, NULL, &backgroundWidth, &backgroundHeight);

    // Create two background rectangles for scrolling
    SDL_Rect background1 = {0, 0, backgroundWidth, 600};
    SDL_Rect background2 = {backgroundWidth, 0, backgroundWidth, 600};

    float scrollSpeed = 200.0f;  // Pixels per second
    Uint32 start, end;

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        start = SDL_GetTicks();

        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Move the backgrounds
        background1.x -= scrollSpeed * (end - start) / 1000.0f;
        background2.x -= scrollSpeed * (end - start) / 1000.0f;

        // Reset position if the first background has scrolled off-screen
        if (background1.x + backgroundWidth < 0) {
            background1.x = background2.x + backgroundWidth;
        }
        if (background2.x + backgroundWidth < 0) {
            background2.x = background1.x + backgroundWidth;
        }

        // Render
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &background1);
        SDL_RenderCopy(renderer, backgroundTexture, NULL, &background2);
        SDL_RenderPresent(renderer);

        // Measure and output the frame time
        end = SDL_GetTicks();
        std::cout << "Frame time: " << (end - start) << " ms" << std::endl;
    }

    // Cleanup
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
