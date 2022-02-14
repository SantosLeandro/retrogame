#pragma once

#include <string>
#include <map>
#include <iostream>
#include <vector>
#include "graphics.h"
#include "vector2.h"
#include <lua.hpp>


class GameObject;

class Component{
protected:

    GameObject *m_pOwner;
    int id = -1;
public:
    Component(){
    }
    Component(GameObject *owner){
        m_pOwner = owner;

    }
    virtual void init(GameObject *owner) {
         m_pOwner = owner;
    }
    virtual void update(float deltatime){}
    virtual void draw(IGraphics *IGraphics){}
};


class StaticSprite: public Component{
   private:
       Texture* m_pTexture;
       Rectangle m_rectangle;

   public:
       StaticSprite(){
       }
       StaticSprite(GameObject *owner): Component(owner){

       }
       void setSprite(Texture* texture, const Rectangle &rect);
       void draw(IGraphics *IGraphics);
};

class SpriteSheet{
    private:
        Texture *m_pTexture;
        std::vector<Rectangle> m_rectangleList;
    public:
        SpriteSheet(){}
        SpriteSheet(Texture *texture){
            m_pTexture = texture;
        }
        void setTexture(Texture *texture){
            m_pTexture = texture;
        }
        Texture* getTexture(){return m_pTexture;}
        Rectangle& getRectangle(int index){ return m_rectangleList[index];}
        void addRectangle(int x, int y, int w, int h){
            m_rectangleList.push_back({x,y,w,h});
        }
};

class Animation{
    private:
        SpriteSheet *m_pSpriteSheet;
        int m_fps = 100;
    public:
        void setSpriteSheet(SpriteSheet *spriteSheet){
            m_pSpriteSheet = spriteSheet;
        }
        SpriteSheet* getSpriteSheet(){return m_pSpriteSheet;}
        void setFps(int fps){
            if(fps == 0){
                m_fps = 1;
            }
            else
                m_fps = fps;

        }

        int getFps(){
            return m_fps;
        }
        std::vector<int> m_sequenceList;
};

class AnimationList{
    public:
        std::map<std::string, Animation> m_animationList;
        Animation get(std::string name){ return m_animationList[name];}
};


class AnimationController: public Component{
    private:
        unsigned int m_ticks = 0;
        unsigned int m_current_frame = 0;
        AnimationList *m_pAnimationList;
        Animation *m_pAnimation;
    public:
        void setAnimation(Animation *animation){
            m_pAnimation = animation;
            m_current_frame = 0;
            m_ticks = 0;
        }

        void update(float deltatime);
        void draw(IGraphics *IGraphics);
    private:
        Rectangle& getRectangle(){
            return m_pAnimation->getSpriteSheet()->getRectangle(m_current_frame);
        }

        Texture* getTexture(){
            return m_pAnimation->getSpriteSheet()->getTexture();
        }
};

class PlayerController: public Component {
   public:
        void update(float deltatime);
        void draw(IGraphics *graphics);
};

class ScriptBehaviour: public Component{
    private:
        bool hasEnded = true;
        Vector2 target;
        Vector2 startPosition;
        Vector2 speed;
        lua_State *state;
    public:
        void setState(lua_State *state){
            this->state = state;
        }
        void move_to(const Vector2 &v, const Vector2 &speed);
        void update(float deltatime);
};


class BoxCollider: public Component{
    private:
        int m_width;
        int m_height;
    public:
        void setSize(int w, int h){
            m_width = w;
            m_height = h;
        }
        Vector2 getPosition();
        int Width(){return m_width;}
        int Height(){return m_height;}
        bool Overlap(BoxCollider &other);

};
