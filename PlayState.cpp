#include "PlayState.h"
#include "InputHandler.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include <stdio.h>

const std::string PlayState::sPlayId = "PLAY";

bool PlayState::onEnter()
{
    printf("PlayState onEnter()\n");

    /*
    if (!TheTextureManager::getInstance()->load("assets/adventurer.png", "adventurer", TheGame::getInstance()->getRenderer()))
    {
        return false;
    }

    GameObject *player = new Player(new LoaderParams(100, 100, 128, 55, "adventurer"));

    mGameObjects.push_back(player);
    */

    return true;
}

bool PlayState::onExit()
{
    for (int i = 0; i < mGameObjects.size(); i++)
    {
        mGameObjects[i]->clean();
    }

    mGameObjects.clear();

    // TheTextureManager::getInstance()->clearFromTextureMap("adventurer");

    return true;
}

void PlayState::update()
{
    printf("PlayState::update1\n");
    for (int i = 0; i < mGameObjects.size(); i++)
    {
        mGameObjects[i]->update();
    }
}

void PlayState::render()
{
    printf("PlayState::render2\n");
    for (int i = 0; i < mGameObjects.size(); i++)
    {
        mGameObjects[i]->draw();
    }
}

bool PlayState::checkCollision(SDLGameObject *p1, SDLGameObject *p2)
{
    int leftA, rightA, topA, bottomA;
    int leftB, rightB, topB, bottomB;

    // Calculate the sides of rect A
    leftA = p1->getPosition().getX();
    rightA = leftA + p1->getWidth();
    topA = p1->getPosition().getY();
    bottomA = topA + p1->getHeight();

    // Calculate the sides of rect B
    leftB = p2->getPosition().getX();
    rightB = leftB + p2->getWidth();
    topB = p2->getPosition().getY();
    bottomB = topB + p2->getHeight();

    // Check for collisions
    if (bottomA <= topB)
    {
        return false;
    }

    if (topA >= bottomB)
    {
        return false;
    }

    if (rightA <= leftB)
    {
        return false;
    }

    if (leftA >= rightB)
    {
        return false;
    }

    return true;
}
