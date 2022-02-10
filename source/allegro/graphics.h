#pragma once

#include "../core/graphics.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <map>

class All_Graphics: public Graphics{
    protected:
        std::map<std::string, Texture*> texture;
        ALLEGRO_FONT* font;
    public:
        void init();
        void drawSprite(float x, float y, Sprite &sprite);
        void drawTile(float x, float y, float src_x, float src_y, int tilesize, void* texture);
        void drawTexture(float x, float y, void* bitmap);
        void drawRectangle(float x, float y, float w, float h);
        void drawText(const char* text, float x, float y);
        void loadTexture(const char* filename);
        Texture* getTexture(const char* filename);
        void clearScreen(int r, int g, int b);
        void flipDisplay();
        void quit();
};
