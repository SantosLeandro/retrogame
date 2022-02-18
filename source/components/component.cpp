#include "component.h"
#include "../core/gameobject.h"
#include <string>

void StaticSprite::setSprite(Texture *texture, const Rectangle &rect) {
  m_pTexture = texture;
  m_rectangle = rect;
}

void StaticSprite::draw(IGraphics *graphics) {
  graphics->draw(m_pOwner->getPosition(), m_rectangle, m_pTexture->get());
}

void AnimationController::update(float deltatime) {
  m_ticks++;
  m_current_frame =
      (m_ticks / m_pAnimation->getFps()) % m_pAnimation->m_sequenceList.size();
}

void AnimationController::draw(IGraphics *graphics) {
  graphics->draw(m_pOwner->getPosition(), getRectangle(), getTexture());
}

void PlayerController::update(float deltatime) {
  if (Keyboard::getKeyDown(1))
    m_pOwner->move(Vector2(-1, 0));
  else if (Keyboard::getKeyDown(4))
    m_pOwner->move(Vector2(1, 0));
}

void PlayerController::draw(IGraphics *graphics) {
  std::string text = "X: " + std::to_string(m_pOwner->getPosition().x) +
                     " Y: " + std::to_string(m_pOwner->getPosition().x);
  graphics->drawText(text.c_str(), 0, 0);
}

void ScriptBehaviour::move_to(const Vector2 &v, const Vector2 &speed) {
  this->target = v;
  this->speed = speed;
  this->startPosition = m_pOwner->getPosition();
}

void ScriptBehaviour::update(float deltatime) {
  if (hasEnded) {
    lua_getglobal(state, "nextTask");
    lua_pushlightuserdata(state, m_pOwner);
    lua_pushlightuserdata(state, this);
    lua_pcall(state, 2, 1, 0);
    lua_pop(state, 1);
    hasEnded = false;
  }
  if (!hasEnded) {
    m_pOwner->getPosition() += speed;
  }
  if (m_pOwner->getPosition() == target) {
    hasEnded = true;
    printf("chegou\n");
  }
}

Vector2 BoxCollider::getPosition() { return m_pOwner->getPosition(); }

bool BoxCollider::Overlap(BoxCollider &other) {
  if ((m_pOwner->getPosition().x + (float)m_width / 2 >
       other.getPosition().x - (float)other.Width() / 2) &&
      (m_pOwner->getPosition().x - (float)m_width / 2 <
       other.getPosition().x + (float)other.Width() / 2) &&
      (m_pOwner->getPosition().y + (float)m_height / 2 >
       other.getPosition().y - (float)other.Height() / 2) &&
      (m_pOwner->getPosition().y - (float)m_height / 2 <
       other.getPosition().y + (float)other.Height() / 2))
    return true;
  else
    return false;
}
