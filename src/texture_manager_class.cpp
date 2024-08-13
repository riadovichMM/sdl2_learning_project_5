#include "../include/SDL2/SDL.h"
#include "../include/SDL2_image/SDL_image.h"
#include "./header_files/texture_manager_class.hpp"


SDL_Texture* Texture_Manager::load_texture(const char* file_name, SDL_Renderer* ptr_renderer) {
    SDL_Surface* tmp_surface = IMG_Load(file_name);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ptr_renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    return texture;
}

