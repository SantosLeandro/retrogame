#pragma once

//#include "component.h"
#include "vector2.h"
#include "graphics.h"
#include "input.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <memory>




class Component;
//class AnimationList;
//class AnimationController;

class GameObject{
    protected:
        Vector2 position;
        Vector2 target;
        float w = 32;
        float h = 32;
    public:
        std::vector<Component*> component;

        float getWidth(){return w;}
        float getHeight(){return h;}
        Vector2& getPosition(){return position;}
        void setPosition(const Vector2 &position){
            this->position = position;
        }

        void move(const Vector2 &vector2){
            position += vector2;
        }

        template <typename T>
        T* addComponent(){
            T *comp = new T();
            comp->init(this);
            component.push_back(comp);
            return comp;
        }

        template <typename T>
        T* getComponent(){
            for(auto &c: component){
                if(std::dynamic_pointer_cast<T>(c))
                    return (T*)c;
            }
        }

        virtual void init(IGraphics *IGraphics){

        }

        virtual void update(float deltatime);

        virtual void draw(IGraphics *IGraphics);

        bool checkCollision(GameObject &go);

};

