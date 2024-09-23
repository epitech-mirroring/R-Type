#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <vector>

int main() {
    // Initialize Allegro and the image addon
    if (!al_init() || !al_init_image_addon()) {
        std::cerr << "Failed to initialize Allegro or image addon!" << std::endl;
        return -1;
    }

    // Create a display
    ALLEGRO_DISPLAY* display = al_create_display(800, 600);
    if (!display) {
        std::cerr << "Failed to create display!" << std::endl;
        return -1;
    }

    // Load an image for the sprite
    ALLEGRO_BITMAP* sprite = al_load_bitmap("tests/sprite.png");
    if (!sprite) {
        std::cerr << "Failed to load sprite image!" << std::endl;
        al_destroy_display(display);
        return -1;
    }

    // Timer to measure frame time
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);  // Targeting 60 FPS
    al_start_timer(timer);

    // Main loop for rendering
    bool running = true;
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    ALLEGRO_EVENT event;
    while (running) {
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        // Clear the screen
        al_clear_to_color(al_map_rgb(0, 0, 0));

        // Draw 1000 sprites
        for (int i = 0; i < 1000; i++) {
            al_draw_bitmap(sprite, rand() % 800, rand() % 600, 0);
        }

        // Flip the display (similar to presenting in other libraries)
        al_flip_display();

        // Measure and output the frame time
        std::cout << "Frame time: " << al_get_timer_count(timer) << " ms" << std::endl;
        al_set_timer_count(timer, 0);  // Reset the timer
    }

    // Cleanup
    al_destroy_bitmap(sprite);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_shutdown_image_addon();

    return 0;
}
