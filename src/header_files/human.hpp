#pragma once

#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"
#include "./camera.hpp"

class Human {
    public:
        Human(SDL_Renderer* ptr_renderer, Camera* camera, int x_pos, int y_pos);
        ~Human();


        void update_state();
        void render();


    private:
        SDL_Renderer* ptr_renderer;
        SDL_Texture* ptr_texture;
        SDL_Rect dest_rect;
        Camera* camera;

        int x_pos;
        int y_pos;

        int x_dir;
        int y_dir;
};
