#pragma once

#include "../core/gameobject.h"
#include "../core/vector2.h"
#include "../core/graphics.h"

class Player: public GameObject{
    private:
     Vector2 mv;
     Sprite sprite;
    public:
        void init(IGraphics *IGraphics);
        void update(float deltatime){
            if(Keyboard::getKeyDown(1))
               position.x -= 1;
            else if(Keyboard::getKeyDown(4))
               position.x += 1;

            GameObject::update(deltatime);
        }
};
