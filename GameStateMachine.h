#ifndef __GAME_STATE_MACHINE__
#define __GAME_STATE_MACHINE__

#include "GameState.h"
#include <vector>
#include <iostream>

class GameStateMachine
{
  public:
    void pushState(GameState *pState);
    void changeState(GameState *pState);
    void popState();
    void update();
    void render();

  private:
    std::vector<GameState *> mGameStates;
};

#endif
