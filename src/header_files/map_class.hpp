#pragma once
#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"
#include "./camera.hpp"


class Map {
    public:
        Map(SDL_Renderer* ptr_renderer, Camera* camera, int rows, int cols);
        ~Map();

        SDL_Texture* tiles;
        SDL_Renderer* ptr_renderer;
        Camera* camera;

        int **matrix;
        int rows;
        int cols;

        int tile_height;
        int tile_width;

        void update_state();
        void render();
};
