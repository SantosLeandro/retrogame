#include "graphics.h"


void All_Graphics::init(){
   font = al_create_builtin_font();
}

void All_Graphics::drawTexture(float x, float y, void* bitmap){
    al_draw_bitmap((ALLEGRO_BITMAP*)bitmap, x, y, 0);
}

void All_Graphics::drawSprite(float x, float y, Sprite &sprite){
    al_draw_bitmap_region((ALLEGRO_BITMAP*)sprite.texture.get(),
    sprite.x, sprite.y, sprite.w, sprite.h, x, y,0);
}

void All_Graphics::drawTile(float x, float y, float src_x, float src_y, int tilesize, void* texture){
    al_draw_bitmap_region((ALLEGRO_BITMAP*)texture,
    src_x, src_y, tilesize, tilesize, x, y,0);
}


void All_Graphics::drawRectangle(float x, float y, float w, float h){
    al_draw_rectangle(x, y, x+w, y+h, al_map_rgb(255, 0, 0), 1);
}

void All_Graphics::drawText(const char* text, float x, float y){
    //al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, "X: %.1f Y: %.1f", x, y);
    al_draw_textf(font, al_map_rgb(255, 255, 255), x, y, 0, text);
}
void All_Graphics::loadTexture(const char* filename){
    ALLEGRO_BITMAP *bmp = al_load_bitmap(filename);
    if(!bmp){
        printf("file not found!");
        return;
    }
    printf("file %s loaded\n",filename);
    bitmap.insert(std::pair<std::string,ALLEGRO_BITMAP*>(filename,bmp));
}


void* All_Graphics::getTexture(const char* filename){
   return bitmap[filename];
}

void All_Graphics::flipDisplay(){
    al_flip_display();
}

void All_Graphics::clearScreen(int r, int g, int b){
    al_clear_to_color(al_map_rgb(r, g, b));
}

void All_Graphics::quit(){
    for (auto &it : bitmap){
            al_destroy_bitmap(it.second);
    }
}


