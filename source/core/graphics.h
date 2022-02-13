#pragma once

#include "vector2.h"
class Texture{
    private:
     void* bitmap = nullptr;
    public:
        Texture(){}
        Texture(void *bitmap){
            this->bitmap = bitmap;
        }
        virtual void* get(){ return bitmap;}
        void set(void* bitmap){
            this->bitmap = bitmap;
        }
};

//class Sprite{
//    public:
//        Texture *texture;
//        int x = 0;
//        int y = 0;
//        int w = 32;
//        int h = 32;
//};

struct Rectangle{
    int x;
    int y;
    int w;
    int h;
    Rectangle(int x, int y, int w, int h):x(x),y(y),w(w),h(h){}
    Rectangle(){}
};

class IGraphics{
    public:
        virtual void init(){}
        virtual void draw(const Vector2 &position, const Rectangle &rect, void* texture){}
        virtual void drawTexture(float x, float y, void* texture){}
        //virtual void drawSprite(float x, float y, Sprite &sprite){}
        virtual void drawTile(float x, float y, float src_x, float src_y, int tilesize, void* texture){}
        virtual void drawRectangle(float x, float y, float w, float h){}
        virtual void drawText(const char* text, float x, float y){}
        virtual void quit(){}
        virtual void loadTexture(const char* filename){}
        virtual void clearScreen(int r, int g, int b){}
        virtual void flipDisplay(){}
        virtual Texture* getTexture(const char* filename){}
};
