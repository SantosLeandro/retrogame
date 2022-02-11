#include "component.h"
#include "gameobject.h"

void StaticSprite::setSprite(Sprite *sprite){
    this->sprite = sprite;
}

void StaticSprite::draw(Graphics *graphics){
    graphics->drawSprite(owner->getPosition().x + sprite->w / 2, owner->getPosition().y + sprite->h / 2, *sprite);
}

void AnimationController::update(float deltatime){
    ticks++;
    current_frame = (ticks / animation->speed) % animation->sequence.size();
}

void AnimationController::draw(Graphics *graphics){
    if(getSprite())
        graphics->drawSprite(owner->getPosition().x + getSprite()->w / 2,
                             owner->getPosition().y + getSprite()->h / 2,
                             *getSprite());
}

void PlayerController::update(float deltatime){

        if(Keyboard::getKeyDown(1))
            owner->move(Vector2(-1,0));
        else if(Keyboard::getKeyDown(4))
            owner->move(Vector2(1,0));


}
