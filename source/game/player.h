#pragma once

#include "../core/gameobject.h"
#include "../core/vector2.h"

class Player: public GameObject{
    private:
     Vector2 mv;
    public:
        void init(Graphics *graphics){
            sprite.w = 32;
            sprite.h = 32;
            sprite.x = 0;
            sprite.y = 0;
            position.x = 0;
            position.y = 0;
            sprite.texture = graphics->getTexture("img/test.png");
        }
        void update(float deltatime){
            if(Keyboard::getKeyDown(1))
               position.x -= 1;
            else if(Keyboard::getKeyDown(4))
               position.x += 1;

            GameObject::update(deltatime);
        }
};
