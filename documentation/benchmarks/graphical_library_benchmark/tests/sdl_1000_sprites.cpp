#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    // Initialize SDL2 and SDL_image
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Initialize SDL_image for PNG support
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
        return -1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("SDL2 Benchmark with PNG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
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

    // Load a PNG image as a texture
    SDL_Surface* surface = IMG_Load("tests/sprite.png");
    if (!surface) {
        std::cerr << "Failed to load image! IMG_Error: " << IMG_GetError() << std::endl;
        return -1;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (!texture) {
        std::cerr << "Failed to create texture! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create an array of SDL_Rects to represent 1000 sprites
    SDL_Rect sprites[1000];
    for (int i = 0; i < 1000; i++) {
        sprites[i] = { rand() % 800, rand() % 600, 50, 50 };  // Random position and size
    }

    // Main loop for rendering
    bool quit = false;
    SDL_Event event;
    Uint32 start, end;

    while (!quit) {
        start = SDL_GetTicks();

        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the renderer
        SDL_RenderClear(renderer);

        // Render all 1000 sprites
        for (int i = 0; i < 1000; i++) {
            SDL_RenderCopy(renderer, texture, NULL, &sprites[i]);
        }

        // Present the renderer to the screen
        SDL_RenderPresent(renderer);

        // Measure and output the frame time
        end = SDL_GetTicks();
        std::cout << "Frame time: " << (end - start) << " ms" << std::endl;
    }

    // Cleanup
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
