#include "../include/SDL2/SDL.h"
#include "./header_files/map_class.hpp"
#include "./header_files/texture_manager_class.hpp"
#include "./header_files/camera.hpp"


Map::Map(SDL_Renderer* ptr_renderer, Camera* camera, int rows, int cols) {
    this->ptr_renderer = ptr_renderer;
    this->rows = rows;
    this->cols = cols;
    this->camera = camera;

    this->tile_height = 64;
    this->tile_width = 64;

    this->tiles = Texture_Manager::load_texture("./src/assets/tiles.png", this->ptr_renderer);

    this->matrix = new int*[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->matrix[i] = new int[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->matrix[i][j] = 0;
        }
    }

    this->matrix[5][5] = 1;
    this->matrix[this->rows - 1][0] = 1;
    this->matrix[0][0] = 1;
    this->matrix[0][this->cols - 1] = 1;
    this->matrix[this->rows - 1][this->cols - 1] = 1;
}

Map::~Map() {
    this->ptr_renderer = nullptr;


    for (int i = 0; i < this->rows; i++) {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;
}


void Map::update_state() {}

void Map::render() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            SDL_Rect src_rect;
            src_rect.h = 64;
            src_rect.w = 64;
            src_rect.x = this->matrix[i][j] * 64;
            src_rect.y = 0;

            SDL_Rect dest_rect;

            dest_rect.w = this->tile_width;
            dest_rect.h = this->tile_height;
            dest_rect.x = j * this->tile_width + this->camera->x;
            dest_rect.y = i * this->tile_height + this->camera->y;

            SDL_RenderCopy(this->ptr_renderer, this->tiles, &src_rect, &dest_rect);
        }
    }
}