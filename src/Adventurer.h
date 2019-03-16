#ifndef __ADVENTURER_H__
#define __ADVENTURER_H__

#include "PlatformerObject.h"
#include "GameObjectFactory.h"
#include <vector>

enum State
{
    STATE_IDLE,
    STATE_DUCK,
    STATE_SPRINT,
    STATE_JUMP,
    STATE_SLIDE,
    STATE_ATTACK
};

class Adventurer : public PlatformerObject
{
  public:
    Adventurer();
    virtual ~Adventurer() {}

    virtual void load(std::unique_ptr<LoaderParams> const &params);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void collision();

    virtual std::string type()
    {
        return "Adventurer";
    }

  private:
    void ressurect();
    void handleInput();
    void handleAnimation();
    void handleMovement(Vector2D velocity);

    int invulnerable;
    int invulnerableTime;
    int invulnerableCounter;

    State state;
};

class AdventurerCreator : public BaseCreator
{
    GameObject *createGameObject() const
    {
        return new Adventurer();
    }
};

#endif