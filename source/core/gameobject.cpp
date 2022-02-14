#include "gameobject.h"
#include "../components/component.h"

void GameObject::update(float deltatime){
            for(auto &c: m_componentList)
                c->update(deltatime);
}

void GameObject::draw(IGraphics *IGraphics){
    std::string text = "X: " + std::to_string(m_position.x) + " Y: " + std::to_string(m_position.y);
    for(auto &c: m_componentList)
                c->draw(IGraphics);
}

bool GameObject::checkCollision(GameObject *go){
//     auto collider = go->getComponent<PlayerController>();
//    if (m_position.x + m_w > go.getPosition().x &&
//        m_position.x < go.getPosition().x + go.getWidth() &&
//        m_position.y + m_h < go.getPosition().y &&
//        m_position.y > go.getPosition().y + go.getHeight())
//        return true;
//    else
//        return false;
    return false;
}
