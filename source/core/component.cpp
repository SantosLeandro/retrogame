#include "component.h"
#include "gameobject.h"

void StaticSprite::setSprite(Sprite *sprite){
    this->sprite = sprite;
}

void StaticSprite::draw(Graphics *graphics){
    graphics->drawSprite(owner->getPosition().x + sprite->w / 2, owner->getPosition().y + sprite->h / 2, *sprite);
}
