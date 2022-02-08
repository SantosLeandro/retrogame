#pragma once

#include "vector2.h"
#include "graphics.h"
#include "input.h"
#include <string>
#include <iostream>

class GameObject{
    protected:
        Vector2 position;
        float w = 32;
        float h = 32;
    public:
        Sprite sprite;
        float getWidth(){return w;}
        float getHeight(){return h;}
        Vector2 getPosition(){return position;}
        void setPosition(const Vector2 &position){
            this->position = position;
        }

        virtual void init(Graphics *graphics){

        }
        virtual void update(float deltatime){

        }

        virtual void draw(Graphics *graphics);

        bool checkCollision(GameObject &go);

};

