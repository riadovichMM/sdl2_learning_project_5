#include <iostream>
#include "./header_files/camera.hpp"


Camera::Camera(int screen_width, int screen_height, int tile_width, int tile_height, int matrix_rows, int matrix_cols) {
    this->x = 0;
    this->y = 0;

    this->x_dir = 0;
    this->y_dir = 0;

    this->screen_width = screen_width;
    this->screen_height = screen_height;

    this->tile_width = tile_width;
    this->tile_height = tile_height;

    this->matrix_rows = matrix_rows;
    this->matrix_cols = matrix_cols;
}


Camera::~Camera() {}


void Camera::update_state() {

    if (this->x_dir != 0) {
        int new_x = this->x + this->x_dir;
        if (((-new_x) + this->screen_width) < (this->tile_width * this->matrix_cols) && (-new_x) >= 0) {
            this->x = new_x;
        }
        this->x_dir = 0;
    }

    if (this->y_dir != 0) {
        int new_y = this->y + this->y_dir;
        if (((-new_y) + this->screen_height) < (this->tile_height * this->matrix_rows) && (-new_y) >= 0) {
            this->y = this->y + this->y_dir;
        }
        this->y_dir = 0;
    }
}
