#pragma once

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

