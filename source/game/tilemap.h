#pragma once

#include "../core/graphics.h"
#include <vector>

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
        void draw(IGraphics *graphics);
        void clear();
};
