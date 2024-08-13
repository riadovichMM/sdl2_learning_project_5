#include <iostream>
#include "./header_files/main_class.hpp"
#include "../include/SDL2/SDL.h"


int main(int argv, char** args) {
    Main* main_obj = new Main();

    main_obj->init("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600);
    main_obj->game_loop();
    main_obj->clean();

    return 0;
}

