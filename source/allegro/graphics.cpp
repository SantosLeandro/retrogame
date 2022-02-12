#include "graphics.h"



Graphics* Graphics::s_pInstance = 0;

Graphics* Graphics::getInstance()
{
    if(s_pInstance == 0)
    {
    s_pInstance = new Graphics();
    return s_pInstance;
    }
    return s_pInstance;
}

void Graphics::init(){
   font = al_create_builtin_font();
}

void Graphics::drawTexture(float x, float y, void* bitmap){
    al_draw_bitmap((ALLEGRO_BITMAP*)bitmap, x, y, 0);
}

void Graphics::drawSprite(float x, float y, Sprite &sprite){
    al_draw_bitmap_region((ALLEGRO_BITMAP*)sprite.texture->get(),
    sprite.x, sprite.y, sprite.w, sprite.h, x, y,0);
}

void Graphics::drawTile(float x, float y, float src_x, float src_y, int tilesize, void* texture){
    al_draw_bitmap_region((ALLEGRO_BITMAP*)texture,
    src_x, src_y, tilesize, tilesize, x, y,0);
}


void Graphics::drawRectangle(float x, float y, float w, float h){
    al_draw_rectangle(x, y, x+w, y+h, al_map_rgb(255, 0, 0), 1);
}

void Graphics::drawText(const char* text, float x, float y){
    //al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, "X: %.1f Y: %.1f", x, y);
    al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, text);
}
void Graphics::loadTexture(const char* filename){
    ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);
    if(!bmp){
        printf("file not found!");
        return;
    }
    printf("file %s loaded\n",filename);
    texture.insert(std::pair<std::string,Texture*>(filename,new Texture(bmp)));
}


Texture* Graphics::getTexture(const char* filename){
   return texture[filename];
}

void Graphics::flipDisplay(){
    al_flip_display();
}

void Graphics::clearScreen(int r, int g, int b){
    al_clear_to_color(al_map_rgb(r, g, b));
}

void Graphics::quit(){
    for (auto &it : texture){
            al_destroy_bitmap((ALLEGRO_BITMAP*)it.second->get());
            delete it.second;
    }
    texture.clear();
}



