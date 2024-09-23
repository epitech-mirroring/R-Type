#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>

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

    // Load the background image
    ALLEGRO_BITMAP* background = al_load_bitmap("tests/sprite.png");
    if (!background) {
        std::cerr << "Failed to load background image!" << std::endl;
        al_destroy_display(display);
        return -1;
    }

    // Set up two backgrounds for scrolling
    float background1_x = 0;
    float background2_x = al_get_bitmap_width(background);

    float scrollSpeed = 200.0f;  // Pixels per second
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);

    bool running = true;
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(event_queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            running = false;
        }

        // Move the backgrounds
        background1_x -= scrollSpeed / 60;
        background2_x -= scrollSpeed / 60;

        // Reset position if a background has scrolled off-screen
        if (background1_x + al_get_bitmap_width(background) < 0) {
            background1_x = background2_x + al_get_bitmap_width(background);
        }
        if (background2_x + al_get_bitmap_width(background) < 0) {
            background2_x = background1_x + al_get_bitmap_width(background);
        }

        // Render
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, background1_x, 0, 0);
        al_draw_bitmap(background, background2_x, 0, 0);
        al_flip_display();

        // Output frame time
        std::cout << "Frame time: " << al_get_time() * 1000 << " ms" << std::endl;
    }

    // Cleanup
    al_destroy_bitmap(background);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);


    return 0;
}
