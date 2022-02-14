#pragma once

#include "vector2.h"
#include "graphics.h"
#include "input.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <memory>

class Component;

class GameObject{
    protected:
        Vector2 m_position;
    public:
        std::vector<Component*> m_componentList;
        Vector2& getPosition(){return m_position;}
        void setPosition(const Vector2 &position){
            this->m_position = position;
        }
        void move(const Vector2 &vector2){
            m_position += vector2;
        }

        template <typename T>
        T* addComponent(){
            T *comp = new T();
            comp->init(this);
            m_componentList.push_back(comp);
            return comp;
        }

        template <typename T>
        T* getComponent(){
            for(auto &c: m_componentList){
                if(std::dynamic_pointer_cast<T>(c))
                    return (T*)c;
            }
        }

        virtual void init(IGraphics *IGraphics){

        }
        virtual void update(float deltatime);

        virtual void draw(IGraphics *IGraphics);

        bool checkCollision(GameObject *go);

};

