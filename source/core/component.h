#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "graphics.h"
#include "vector2.h"
//#include "gameobject.h"
//class Sprite;
//class IGraphics;
//class GameObject;

class GameObject;

class Component{
protected:
    GameObject *owner;
    int id = -1;
public:
    Component(){
    }
    Component(GameObject *owner){
        this->owner = owner;

    }
    void generateId(int id){
        if(this->id == -1)
            this->id = id;
    }
    virtual void init(GameObject *owner) {
        this->owner = owner;
    }
    virtual void update(float deltatime){}
    virtual void draw(IGraphics *IGraphics){}
};


class StaticSprite: public Component{
   private:
       Texture* texture;
       Rectangle rect;

   public:
       StaticSprite(){
       }
       StaticSprite(GameObject *owner): Component(owner){

       }
       void setSprite(Texture* texture, const Rectangle &rect);
       void draw(IGraphics *IGraphics);
};

//class SpriteList{
//    private:
//        Texture* texture;
//        std::vector<Rectangle> rect;
//        std::vector<Sprite> sprite;
//    public:
//        void addRect(const Rectangle &rect){
//            this->rect.push_back(rect);
//        }
//        void addSprite(Sprite sprite){
//            this->sprite.push_back(sprite);
//        }
//
//        Texture* getTexture(){return texture; }
//        Rectangle& getRectangle(int index){ return rect[index];}
//        Sprite* getSprite(int i){ return &sprite[i];}
//};


class SpriteSheet{
    private:
        Texture *texture;
        std::vector<Rectangle> rectangle;
    public:
        SpriteSheet(){}
        SpriteSheet(Texture *texture){
            this->texture = texture;
        }
        void setTexture(Texture *texture){
            this->texture = texture;
        }
        Texture* getTexture(){return texture;}
        Rectangle& getRectangle(int index){ return rectangle[index];}
        void addRectangle(int x, int y, int w, int h){
            rectangle.push_back({x,y,w,h});
        }
};

class Animation{
    protected:
        SpriteSheet *spriteSheet;
    public:
        //SpriteList *spriteList;
        void setSpriteSheet(SpriteSheet *spriteSheet){
            this->spriteSheet = spriteSheet;
        }
        SpriteSheet* getSpriteSheet(){return spriteSheet;}
        unsigned int speed = 100;
        //Sprite* getCurrentSprite(int idx){return spriteList->getSprite(this->sequence[idx]); }
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
        void draw(IGraphics *IGraphics);
    private:
        Rectangle& getRectangle(){
            return animation->getSpriteSheet()->getRectangle(current_frame);
        }

        Texture* getTexture(){
            return animation->getSpriteSheet()->getTexture();
        }
//        Sprite* getSprite(){
//            return animation->getCurrentSprite(current_frame);
//        }
};

class PlayerController: public Component {
   public:
        void update(float deltatime);

};

class ScriptBehaviour: public Component{
    private:
        std::string functionName;
        bool hasEnded = false;
        Vector2 target;
        float speed;
    public:
        void move_to(const Vector2 &v, float speed);
        void update(float deltatime);
};



//enum COMPONENET_ID {
//    STATIC_SPRITE = 0,
//    ANIMATED_SPRITE,
//    PLAYER_BEHAVIOUR,
//    SCRIPT_BEHAVIOUR
//};
//
//class ComponentManager{
//    public:
//        static Component* createComponent(int cid){
//            switch(cid){
//            case STATIC_SPRITE: return new StaticSprite(); break;
//            case ANIMATED_SPRITE: return new StaticSprite(); break;
//            case PLAYER_BEHAVIOUR: return new PlayerController(); break;
//            case SCRIPT_BEHAVIOUR: return new ScriptBehaviour(); break;
//            }
//        }
//};
