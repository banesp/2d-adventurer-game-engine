#ifndef __OBJECT_LAYER_H__
#define __OBJECT_LAYER_H__

#include "Layer.h"
#include "CollisionManager.h"
#include <iostream>
#include <vector>

class GameObject;

class ObjectLayer : public Layer
{
  public:
    virtual ~ObjectLayer();

    virtual void update(Level *pLevel);
    virtual void render();

    // return a pointer to this layers objects, the level parser will fill this
    std::vector<GameObject *> *getGameObjects() { return &m_gameObjects; }

  private:
    // check for collisions between game objects
    CollisionManager m_collisionManager;

    // a list of game objects
    std::vector<GameObject *> m_gameObjects;
};

#endif
