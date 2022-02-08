#pragma once


class Texture{
    private:
     void* tex = nullptr;
    public:
        virtual void* get(){ return tex;}
        void set(void* texture){
            this->tex = texture;
        }
};

class Sprite{
    public:
        Texture texture;
        int x = 0;
        int y = 0;
        int w = 32;
        int h = 32;
};

class Graphics{
    public:
        virtual void init(){}
        virtual void drawTexture(float x, float y, void* texture){}
        virtual void drawSprite(float x, float y, Sprite &sprite){}
        virtual void drawTile(float x, float y, float src_x, float src_y, int tilesize, void* texture){}
        virtual void drawRectangle(float x, float y, float w, float h){}
        virtual void drawText(const char* text, float x, float y){}
        virtual void quit(){}
        virtual void loadTexture(const char* filename){}
        virtual void clearScreen(int r, int g, int b){}
        virtual void flipDisplay(){}
        virtual void* getTexture(const char* filename){}
};