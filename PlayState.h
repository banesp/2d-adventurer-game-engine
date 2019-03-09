#ifndef __PLAY_STATE_H__
#define __PLAY_STATE_H__

#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <iostream>
#include <vector>

class PlayState : public GameState
{
public:
  virtual bool onEnter();
  virtual bool onExit();
  virtual void update();
  virtual void render();

  virtual std::string getStateId() const
  {
    return sPlayId;
  }

  bool checkCollision(SDLGameObject *p1, SDLGameObject *p2);

private:
  static const std::string sPlayId;
  std::vector<GameObject *> mGameObjects;
};

#endif