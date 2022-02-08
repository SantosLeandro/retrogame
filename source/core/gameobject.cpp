#include "gameobject.h"

void GameObject::draw(Graphics *graphics){
    std::string text = "X: " + std::to_string(position.x) + " Y: " + std::to_string(position.y);
    graphics->drawText(text.c_str(), 0, 0);
    graphics->drawSprite(position.x + sprite.w / 2, position.y + sprite.h / 2, sprite);
    graphics->drawRectangle(position.x + sprite.w / 2, position.y + sprite.h / 2, sprite.w, sprite.h);
}

bool GameObject::checkCollision(GameObject &go){
    if (position.x + w > go.getPosition().x &&
        position.x < go.getPosition().x + go.getWidth() &&
        position.y + h < go.getPosition().y &&
        position.y > go.getPosition().y + go.getHeight())
        return true;
    else
        return false;
}