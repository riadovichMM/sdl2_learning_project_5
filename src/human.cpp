#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./header_files/human.hpp"
#include "./header_files/texture_manager_class.hpp"
#include "./header_files/human.hpp"
#include <vector>
#include <cmath>

Human::Human(SDL_Renderer* ptr_renderer, Camera* camera, int x_pos, int y_pos, int type, int id,  std::vector<Human>* human_array) {
    this->ptr_renderer = ptr_renderer;

    this->x_pos = x_pos;
    this->y_pos = y_pos;
    this->id = id;

    this->x_dir = 1;
    this->y_dir = 0;
    this->human_array = human_array;


    this->dest_rect.h = 32;
    this->dest_rect.w = 32;
    this->dest_rect.x = this->x_pos;
    this->dest_rect.y = this->y_pos;

    this->camera = camera;
    this->type = type;
    if (type == 0) {
        this->ptr_texture = Texture_Manager::load_texture("./src/assets/human_blue.png", this->ptr_renderer);
    } else {
        this->ptr_texture = Texture_Manager::load_texture("./src/assets/human_red.png", this->ptr_renderer);
    }
}


Human::~Human() {
    this->camera = nullptr;
}

void Human::update_state() {
    this->x_pos = this->x_pos + this->x_dir;
}

void Human::render() {
    this->dest_rect.x = this->x_pos + this->camera->x;
    this->dest_rect.y = this->y_pos + this->camera->y;

    SDL_RenderCopy(this->ptr_renderer, this->ptr_texture, nullptr, &this->dest_rect);
}

