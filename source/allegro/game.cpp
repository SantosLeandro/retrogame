#include "game.h"
#include <iostream>
#include <cstdio>
#include "../core/input.h"
#include "../components/component.h"

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

    m_pTimer = al_create_timer(1.0 / 30.0);
    must_init(m_pTimer,"timer 1/30");

    m_pQueue = al_create_event_queue();
    must_init(m_pQueue,"queue");

    m_pDisplay = al_create_display(width, height);
    must_init(m_pDisplay, "display");

    must_init(al_init_image_addon(),"image addon" );


    al_register_event_source(m_pQueue, al_get_keyboard_event_source());
    al_register_event_source(m_pQueue, al_get_display_event_source(m_pDisplay));
    al_register_event_source(m_pQueue, al_get_timer_event_source(m_pTimer));

    m_done = false;
    al_start_timer(m_pTimer);

    m_pKey = new int[ALLEGRO_KEY_MAX];
    for(int i=0; i < ALLEGRO_KEY_MAX;i++){
        m_pKey[i] = 0;
    }

    Graphics::getInstance()->init();

    Keyboard::init(m_pKey);
    Graphics::getInstance()->init();
    Graphics::getInstance()->loadTexture("img/test.png");
    Graphics::getInstance()->loadTexture("img/test.png");
    Graphics::getInstance()->loadTexture("img/tileset.png");


}

void AllegroGame::run(){
     m_levelManager.load("level/main.lua");
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
    while(!m_done){
         al_wait_for_event(m_pQueue, &m_event);
         switch(m_event.type)
         {
            case ALLEGRO_EVENT_TIMER:
            AllegroGame::update();
                for(int i = 0; i < ALLEGRO_KEY_MAX; i++)
                    m_pKey[i] &= KEY_SEEN;
            redraw = true;
            break;
            case ALLEGRO_EVENT_KEY_DOWN:
                m_pKey[m_event.keyboard.keycode] = KEY_SEEN | KEY_RELEASED;; break;
            case ALLEGRO_EVENT_KEY_UP:
                m_pKey[m_event.keyboard.keycode] &= KEY_RELEASED; break;
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                m_done = true;
            break;
         }

         if(redraw && al_is_event_queue_empty(m_pQueue)){
             AllegroGame::draw();
             redraw = false;
         }


    }
}

void AllegroGame::update(){
    m_levelManager.update(0);
}

void AllegroGame::draw(){
    Graphics::getInstance()->clearScreen(0,0,0);
    m_levelManager.draw(Graphics::getInstance());
    Graphics::getInstance()->flipDisplay();
}

void AllegroGame::quit(){
    Graphics::getInstance()->quit();
    al_destroy_display(m_pDisplay);
    al_destroy_timer(m_pTimer);
    al_destroy_event_queue(m_pQueue);
}
