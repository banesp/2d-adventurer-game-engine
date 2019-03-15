#ifndef __COLLISIONMANAGER_H__
#define __COLLISIONMANAGER_H__

#include <iostream>
#include <vector>

class Player;
class GameObject;

class CollisionManager
{
public:
  void checkPlayerGameObjectCollision(Player *pPlayer, const std::vector<GameObject *> &objects);
};

#endif
