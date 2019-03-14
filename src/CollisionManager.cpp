#include "CollisionManager.h"
#include "Collision.h"
#include "Player.h"
#include "Enemy.h"
#include "TileLayer.h"
#include "Game.h"
#include "GameOverState.h"
#include <iostream>

void CollisionManager::checkPlayerGameObjectCollision(Player *pPlayer, const std::vector<GameObject *> &objects)
{
    SDL_Rect *pRect1 = new SDL_Rect();
    pRect1->x = pPlayer->getPosition().getX();
    pRect1->y = pPlayer->getPosition().getY();
    pRect1->w = pPlayer->getWidth();
    pRect1->h = pPlayer->getHeight();

    for (int i = 0; i < objects.size(); i++)
    {
        if (!objects[i]->updating())
        {
            continue;
        }

        SDL_Rect *pRect2 = new SDL_Rect();
        pRect2->x = objects[i]->getPosition().getX();
        pRect2->y = objects[i]->getPosition().getY();
        pRect2->w = objects[i]->getWidth();
        pRect2->h = objects[i]->getHeight();

        if (RectRect(pRect1, pRect2))
        {

            // If object type is enemy we want to do this
            if (objects[i]->type() == std::string("Enemy"))
            {
                std::cout << "Player collided with enemy)\n";
                if (!objects[i]->dead() && !objects[i]->dying())
                {
                    pPlayer->collision();
                }
            }

            // If object type is jewel, we want to finish the level
            else if (objects[i]->type() == std::string("Jewel"))
            {
                std::cout << "Player collided with jewel\n";
                TheGame::getInstance()->getStateMachine()->changeState(new GameOverState());
            }
        }

        delete pRect2;
    }

    delete pRect1;
}
