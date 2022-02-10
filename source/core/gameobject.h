#pragma once

#include "component.h"
#include "vector2.h"
#include "graphics.h"
#include "input.h"
#include <string>
#include <map>
#include <iostream>
#include <vector>



class SpriteList{
    private:
        std::vector<Sprite> sprite;
    public:
        void addSprite(Sprite &sprite){
            this->sprite.push_back(sprite);
        }
        Texture* getTexture(){}
        Sprite* getSprite(int i){ return &sprite[i];}
};

class Animation{
    public:
        SpriteList *spriteList;
        unsigned int speed = 100;
        Sprite* getCurrentSprite(int idx){return spriteList->getSprite(this->sequence[idx]); }
        std::vector<int> sequence;
};

class AnimationList{
    public:
        std::map<std::string, Animation> animation;
        Animation get(std::string name){ return animation[name];}
};

class AnimationController: public Component{
    private:
        unsigned int ticks = 0;
        unsigned int current_frame = 0;
        AnimationList *animationList;
        Animation *animation;
    public:
        void setAnimation(Animation *animation){
            this->animation = animation;
            current_frame = 0;
            ticks = 0;
        }

        void updater(float deltatime){
            ticks++;
        }

        void draw(Graphics *Graphics){

        }

        void play(){

            ticks++;
        }
        Sprite* getSprite(){
            current_frame = (ticks / animation->speed) % animation->sequence.size();
            return animation->getCurrentSprite(current_frame);
        }
};



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

