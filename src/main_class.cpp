#include <iostream>
#include "../include/SDL2/SDL.h"
#include "./header_files/main_class.hpp"
#include "./header_files/map_class.hpp"
#include "./header_files/human.hpp"

Main::Main() {}
Main::~Main() {}

void Main::init(const char* title, int x_pos, int y_pos, int screen_width, int screen_height) {
    SDL_Init(SDL_INIT_EVERYTHING);

    this->ptr_window = SDL_CreateWindow(title, x_pos, y_pos, screen_width, screen_height, SDL_WINDOW_SHOWN);
    this->ptr_renderer = SDL_CreateRenderer(this->ptr_window, -1, SDL_RENDERER_ACCELERATED);
    this->run_loop = true;
    this->frame_count = 0;

    int tile_height = 64;
    int tile_width = 64;

    int matrix_rows = 10;
    int matrix_cols = 15;

    this->camera = new Camera(screen_width, screen_height, tile_width, tile_height, matrix_rows, matrix_cols);
    this->map = new Map(this->ptr_renderer, this->camera, matrix_rows, matrix_cols);
    this->human = new Human(this->ptr_renderer, this->camera, 100, 100);
}


void Main::clean() {
    delete this->map;
    delete this->camera;
    delete this->human;

    SDL_DestroyRenderer(this->ptr_renderer);
    SDL_DestroyWindow(this->ptr_window);
    SDL_Quit();
}


void Main::handle_event() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->run_loop = false;
        }
    }


    const Uint8 *state = SDL_GetKeyboardState(nullptr);

    if (state[SDL_SCANCODE_W]) {
        this->camera->y_dir = 1;
    }

    if (state[SDL_SCANCODE_S]) {
        this->camera->y_dir = -1;
    }

    if (state[SDL_SCANCODE_D]) {
        this->camera->x_dir = -1;
    }

    if (state[SDL_SCANCODE_A]) {
        this->camera->x_dir = 1;
    }
}

void Main::update_state() {
    this->camera->update_state();

    this->map->update_state();
    this->human->update_state();
}

void Main::render() {
    SDL_SetRenderDrawColor(this->ptr_renderer, 0, 0, 0, 0);
    SDL_RenderClear(this->ptr_renderer);

    this->map->render();
    this->human->render();

    SDL_RenderPresent(this->ptr_renderer);
}


void Main::game_loop() {
    while(this->run_loop) {
        this->frame_count++;

        this->handle_event();

        if (this->frame_count == 100) {
            this->update_state();
            this->frame_count = 0;
        }

        this->render();
    }
}

