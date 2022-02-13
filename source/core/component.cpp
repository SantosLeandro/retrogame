#include "component.h"
#include "gameobject.h"
#include <string>


void StaticSprite::setSprite(Texture* texture, const Rectangle &rect){
    this->texture = texture;
    this->rect = rect;
}

void StaticSprite::draw(IGraphics *graphics){
    //graphics->draw(owner->getPosition().x + sprite.w / 2, owner->getPosition().y + sprite.h / 2, sprite);
    graphics->draw(owner->getPosition(), rect, texture->get());
}

void AnimationController::update(float deltatime){
    ticks++;
    current_frame = (ticks / animation->speed) % animation->sequence.size();
}

void AnimationController::draw(IGraphics *graphics){

    graphics->draw(owner->getPosition(),getRectangle(),getTexture());
//    if(getSprite())
//        graphics->drawSprite(owner->getPosition().x + getSprite()->w / 2,
//                             owner->getPosition().y + getSprite()->h / 2,
//                             *getSprite());
}

void PlayerController::update(float deltatime){
        if(Keyboard::getKeyDown(1))
            owner->move(Vector2(-1,0));
        else if(Keyboard::getKeyDown(4))
            owner->move(Vector2(1,0));

}

void PlayerController::draw(IGraphics *graphics){
    std::string text = "X: " + std::to_string(owner->getPosition().x) + " Y: " + std::to_string(owner->getPosition().x);
    graphics->drawText(text.c_str(), 0, 0);
}

void ScriptBehaviour::move_to(const Vector2 &v, const Vector2 &speed){
    this->target = v;
    this->speed = speed;
    this->startPosition = owner->getPosition();
}

void ScriptBehaviour::update(float deltatime){
    if(hasEnded){
        lua_getglobal(state, functionName.c_str());
        lua_pushlightuserdata(state, this);
        lua_pcall(state, 1, 1, 0);
        lua_pop(state, 1);
        hasEnded = false;
    }
    if(!hasEnded){

        owner->getPosition() +=  speed;
        //printf("POSICAO x: %d y: %d", owner->getPosition().x, owner->getPosition().y);
    }
    if( owner->getPosition() == target){
        hasEnded = true;
        printf("chegou\n");
    }

}
