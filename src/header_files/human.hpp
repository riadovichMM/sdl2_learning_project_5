#pragma once

#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"
#include "./camera.hpp"
#include <vector>

class Human {
    public:
        Human(SDL_Renderer* ptr_renderer, Camera* camera, int x_pos, int y_pos, int type, int id, std::vector<Human>* humans_vector);
        ~Human();


        void update_state();
        void render();

    private:
        SDL_Renderer* ptr_renderer;
        SDL_Texture* ptr_texture;
        SDL_Rect dest_rect;
        Camera* camera;
        std::vector<Human>* human_array;
        int id;

        int x_pos;
        int y_pos;

        int x_dir;
        int y_dir;
        int type;
};
