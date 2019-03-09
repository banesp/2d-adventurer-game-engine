#ifndef __GAME_STATE_H__
#define __GAME_STATE_H__

#include <iostream>

class GameState
{
  public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    virtual std::string getStateId() const = 0;
};

#endif
