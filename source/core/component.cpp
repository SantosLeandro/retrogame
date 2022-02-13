#include "component.h"
#include "gameobject.h"

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

void ScriptBehaviour::move_to(const Vector2 &v, float speed){
    target = v;
}

void ScriptBehaviour::update(float deltatime){

}
