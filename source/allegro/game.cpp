#include "game.h"
#include <iostream>
#include <cstdio>
#include "../core/input.h"
#include "../core/component.h"

void AllegroGame::must_init(bool test, const char *description){
    if(!test){
       printf("couldn't initialize %s\n", description);
       exit(1);
    }
    printf("initialized %s\n", description);
}

void AllegroGame::init(){
    int width = 640;
    int height = 480;

    must_init(al_init(),"al_init()");

    ALLEGRO_CONFIG* cfg = al_load_config_file("config/main.cfg");
    if(cfg){
        width = atoi(al_get_config_value(cfg, "video", "width"));
        height = atoi(al_get_config_value(cfg, "video", "height"));
        printf("width = %d\n",width);
        printf("height = %d\n",height);
    }
     al_destroy_config(cfg);




    must_init(al_install_keyboard(),"keyboard");

    timer = al_create_timer(1.0 / 30.0);
    must_init(timer,"timer 1/30");

    queue = al_create_event_queue();
    must_init(queue,"queue");

    disp = al_create_display(width, height);
    must_init(disp, "display");

    must_init(al_init_image_addon(),"image addon" );


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    done = false;
    al_start_timer(timer);

    key = new int[ALLEGRO_KEY_MAX];
    for(int i=0; i < ALLEGRO_KEY_MAX;i++){
        key[i] = 0;
    }

    Graphics::getInstance()->init();

    Keyboard::init(key);
    Graphics::getInstance()->init();
    Graphics::getInstance()->loadTexture("img/test.png");
    Graphics::getInstance()->loadTexture("img/tileset.png");


}

void AllegroGame::run(){
    levelManager.load("level/level02.lua");
//   SpriteList spriteList;
    //Sprite sprite;
   //sprite.texture = Graphics::getInstance()->getTexture("img/test.png");
//   spriteList.addSprite(sprite);
////
//    Animation animation_idle;
//    animation_idle.sequence.push_back(0);
//    animation_idle.spriteList = &spriteList;
////
////    AnimationList animationList;
////    animationList.animation["idle"] = animation_idle;


//    GameObject *player = level.newGameObject();
//    player->setPosition(Vector2{100,100});
//    player->addComponent<PlayerController>();
//    StaticSprite *static_sprite = player->addComponent<StaticSprite>();
//    static_sprite->setSprite(&sprite);
//    player.get()->animationController.setAnimation(&animation_idle);
//    level.load("level/level01.lua", Graphics::getInstance());




    bool redraw = true;
    while(!done){
         al_wait_for_event(queue, &event);
         switch(event.type)
         {
            case ALLEGRO_EVENT_TIMER:
            AllegroGame::update();
                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    key[i] &= KEY_SEEN;
            redraw = true;
            break;
            case ALLEGRO_EVENT_KEY_DOWN:
                key[event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;; break;
            case ALLEGRO_EVENT_KEY_UP:
                key[event.keyboard.keycode] &= KEY_RELEASED; break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
            break;
         }

         if(redraw && al_is_event_queue_empty(queue)){
             AllegroGame::draw();
             redraw = false;
         }


    }
}

void AllegroGame::update(){
    levelManager.update(0);
}

void AllegroGame::draw(){
    Graphics::getInstance()->clearScreen(0,0,0);
    levelManager.draw(Graphics::getInstance());
    Graphics::getInstance()->flipDisplay();
}

void AllegroGame::quit(){
    Graphics::getInstance()->quit();
     al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
}
