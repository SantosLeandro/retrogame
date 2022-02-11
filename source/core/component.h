#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>

class Sprite;
class Graphics;
class GameObject;


class Component{
protected:
    GameObject *owner;
public:
    Component(){
    }
    Component(GameObject *owner){
        this->owner = owner;
    }
    virtual void init(GameObject *owner) {
        this->owner = owner;
    }
    virtual void update(float deltatime){}
    virtual void draw(Graphics *graphics){}
};


class StaticSprite: public Component{
   private:
       Sprite *sprite;
   public:
       StaticSprite(){
       }
       StaticSprite(GameObject *owner): Component(owner){
       }
       void setSprite(Sprite *sprite);
       void draw(Graphics *graphics);
};

class SpriteList{
    private:
        std::vector<Sprite> sprite;
    public:
        void addSprite(Sprite &sprite){
            this->sprite.push_back(sprite);
        }
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

        void update(float deltatime);
        void draw(Graphics *Graphics);
        Sprite* getSprite(){
            return animation->getCurrentSprite(current_frame);
        }
};

class PlayerController: public Component {
   public:
        void update(float deltatime);

};

