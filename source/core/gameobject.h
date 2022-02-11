#pragma once

#include "component.h"
#include "vector2.h"
#include "graphics.h"
#include "input.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>






class GameObject{
    protected:
        Vector2 position;
        float w = 32;
        float h = 32;
    public:
        std::vector<Component*> component;
        AnimationList *animationList;
        AnimationController animationController;

        Sprite sprite;
        float getWidth(){return w;}
        float getHeight(){return h;}
        Vector2 getPosition(){return position;}
        void setPosition(const Vector2 &position){
            this->position = position;
        }

        void move(Vector2 vector2){
            position = position + vector2;
        }

        template <typename T>
        T* addComponent(){
            T *comp = new T();
            comp->init(this);
            component.push_back(comp);
            return comp;
        }

        virtual void init(Graphics *graphics){

        }

        virtual void update(float deltatime){
            for(auto &c: component)
                c->update(deltatime);

            //animationController.play();
        }

        virtual void draw(Graphics *graphics);

        bool checkCollision(GameObject &go);

};

