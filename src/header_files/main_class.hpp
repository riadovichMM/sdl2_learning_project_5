#pragma once
#include "../../include/SDL2/SDL.h"
#include "./map_class.hpp"
#include "./camera.hpp"
#include "./human.hpp"

class Main {
    public:
        Main();
        ~Main();

        void init(const char* title, int x_pos, int y_pos, int screen_width, int screen_height);
        void clean();

        void handle_event();
        void update_state();
        void render();

        void game_loop();

    private:
        bool run_loop;
        SDL_Window* ptr_window;
        SDL_Renderer* ptr_renderer;
        int frame_count;
        Map* map;
        Camera* camera;
        Human* human;
};

