#pragma once

class Camera {
    public:
        int x;
        int y;

        int x_dir;
        int y_dir;

        int matrix_rows;
        int matrix_cols;

        int screen_width;
        int screen_height;

        int tile_width;
        int tile_height;

        Camera(int screen_width, int screen_height, int tile_width, int tile_height, int matrix_rows, int matrix_cols);
        ~Camera();


        void update_state();
};
