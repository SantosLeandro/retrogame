#pragma once

#include "../core/graphics.h"
#include <vector>

int** create_2d_array(int w, int h);

class Tilemap{
    protected:
    Texture *texture;
    int width;
    int height;
    int col;
    int tilesize;
    std::vector<int> map;
    public:
        void init(int width, int height,int col, int tilesize, Texture *texture, std::vector<int> map);
        void draw(Graphics *graphics);
        void clear();
};
