#include "../include/SDL2/SDL.h"
#include "./header_files/human.hpp"
#include "./header_files/texture_manager_class.hpp"
#include "./header_files/human.hpp"


Human::Human(SDL_Renderer* ptr_renderer, Camera* camera, int x_pos, int y_pos) {
    this->ptr_renderer = ptr_renderer;

    this->x_pos = x_pos;
    this->y_pos = y_pos;

    this->x_dir = 1;
    this->y_dir = 0;

    this->ptr_texture = Texture_Manager::load_texture("./src/assets/human.png", this->ptr_renderer);

    this->dest_rect.h = 32;
    this->dest_rect.w = 32;
    this->dest_rect.x = this->x_pos;
    this->dest_rect.y = this->y_pos;

    this->camera = camera;
}


Human::~Human() {
    this->camera = nullptr;
}

void Human::update_state() {
    // this->x_pos = this->x_pos + this->x_dir;
}

void Human::render() {
    this->dest_rect.x = this->x_pos + this->camera->x;
    this->dest_rect.y = this->y_pos + this->camera->y;


    SDL_RenderCopy(this->ptr_renderer, this->ptr_texture, nullptr, &this->dest_rect);
}

