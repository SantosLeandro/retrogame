#include "gameobject.h"
#include "component.h"


void GameObject::update(float deltatime){
            for(auto &c: component)
                c->update(deltatime);

            //animationController.play();
        }

void GameObject::draw(IGraphics *IGraphics){
    std::string text = "X: " + std::to_string(position.x) + " Y: " + std::to_string(position.y);
    for(auto &c: component)
                c->draw(IGraphics);

    //IGraphics->drawSprite(position.x + sprite.w / 2, position.y + sprite.h / 2, sprite);

//    if(animationController.getSprite())
//        IGraphics->drawSprite(position.x + animationController.getSprite()->w / 2,
//                             position.y + animationController.getSprite()->h / 2,
//                             *animationController.getSprite());
//
//    IGraphics->drawRectangle(position.x + sprite.w / 2, position.y + sprite.h / 2, sprite.w, sprite.h);
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
