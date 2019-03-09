#include "AnimatedGraphic.h"

AnimatedGraphic::AnimatedGraphic(const LoaderParams *pParams, int animSpeed) : SDLGameObject(pParams), m_animSpeed(animSpeed)
{
}

void AnimatedGraphic::update()
{
  m_currentFrame = (((SDL_GetTicks() / (1000 / m_animSpeed))));
}

void AnimatedGraphic::draw()
{
}

void AnimatedGraphic::clean()
{
}