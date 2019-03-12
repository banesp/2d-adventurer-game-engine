#ifndef __PLATFORMER_OBJECT_H__
#define __PLATFORMER_OBJECT_H__

#include "GameObject.h"
#include <SDL2/SDL.h>

class PlatformerObject : public GameObject
{
  public:
    virtual ~PlatformerObject() {}

    virtual void load(std::unique_ptr<LoaderParams> const &pParams);

    virtual void draw();
    virtual void update();

    virtual void clean() {}
    virtual void collision() {}

    virtual std::string type() { return "SDLGameObject"; }

  protected:
    PlatformerObject();

    bool checkCollideTile(Vector2D newPos);

    void doDyingAnimation();

    int m_bulletFiringSpeed;
    int m_bulletCounter;
    int m_moveSpeed;

    // Length of death animation and count
    int m_dyingTime;
    int m_dyingCounter;

    bool m_bPlayedDeathSound;

    bool m_bFlipped;

    // Movement
    bool m_bMoveLeft;
    bool m_bMoveRight;
    bool m_bRunning;

    bool m_bFalling;
    bool m_bJumping;
    bool m_bCanJump;

    Vector2D m_lastSafePos;

    int m_jumpHeight;
};

#endif