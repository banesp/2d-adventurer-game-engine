#ifndef __ANIMATED_GRAPHIC_H__
#define __ANIMATED_GRAPHIC_H__

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include <SDL2/SDL.h>

class AnimatedGraphic : public SDLGameObject
{
public:
  AnimatedGraphic(const LoaderParams *pParams, int animSpeed);

  virtual void update();
  virtual void draw();
  virtual void clean();

private:
  int m_animSpeed;
};

#endif
