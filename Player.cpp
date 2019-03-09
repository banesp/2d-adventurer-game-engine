#include "Player.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include <SDL2/SDL.h>

Player::Player(const LoaderParams *pParams) : SDLGameObject(pParams)
{
}

void Player::draw()
{
  SDLGameObject::draw();
}

void Player::update()
{
  m_velocity.setX(0);
  m_velocity.setY(0);

  handleInput();

  m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

  SDLGameObject::update();
}

void Player::clean()
{
}

void Player::handleInput()
{
  Vector2D *target = TheInputHandler::getInstance()->getMousePosition();
  m_velocity = *target - m_position;
  m_velocity /= 50;
}