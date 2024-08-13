#pragma once
#include "../../include/SDL2/SDL.h"
#include "../../include/SDL2_image/SDL_image.h"



class Texture_Manager {
    public:
        static SDL_Texture* load_texture(const char* file_name, SDL_Renderer* ptr_renderer);
};
