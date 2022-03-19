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
	auto colliderOther = go->getComponent<BoxCollider>();
	auto collider = getComponent<BoxCollider>();
	if(collider){
		return collider->Overlap(colliderOther);
	}
    return false;
}
