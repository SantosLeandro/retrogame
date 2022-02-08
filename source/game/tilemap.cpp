#include "tilemap.h"

#include <iostream>
#include <fstream>
#include <lua.hpp>

int** create_2d_array(int w, int h){
    int** array = new int*[w];
    for(int i = 0; i < h ; i++){
        array[i] = new int[h];
    }
    return array;
}

void Tilemap::init(int width, int height,int col, int tilesize, Texture *texture, std::vector<int> map){
    this->width = width;
    this->height = height;
    this->texture = texture;
    this->tilesize = tilesize;
    this->col = col;
    this->map = map;
}

void Tilemap::draw(Graphics *graphics){
    int src_x = 0;
    int src_y = 0;
    int dst_x = 0;
    int dst_y = 0;
    for(int i=0; i < map.size();i++){
        src_x = map[i] % col * tilesize;
        src_y = map[i] / col * tilesize;

        dst_y = i / width * tilesize;
        dst_x = i % width * tilesize;

        graphics->drawTile(dst_x,dst_y,src_x,src_y,tilesize, texture->get());
    }
}

void Tilemap::clear(){

}