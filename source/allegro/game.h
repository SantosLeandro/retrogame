#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

#include "../core/game.h"
#include "graphics.h"
#include "../game/player.h"
#include "../game/world.h"

#define KEY_SEEN     1
#define KEY_RELEASED 2

class AllegroGame: public Game{
    private:
        ALLEGRO_TIMER* timer;
        ALLEGRO_EVENT_QUEUE* queue;
        ALLEGRO_DISPLAY* disp;
        ALLEGRO_EVENT event;
        All_Graphics graphics;
        World world;
    private:
        void must_init(bool test, const char *description);
    public:
        void init();
        void update();
        void draw();
        void run();
        void quit();
};
