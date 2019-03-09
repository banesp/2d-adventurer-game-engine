#include "PlayState.h"
#include "InputHandler.h"
#include "Game.h"
#include "Player.h"

const std::string PlayState::sPlayId = "PLAY";

void PlayState::update()
{
    for (int i = 0; i < mGameObjects.size(); i++)
    {
        mGameObjects[i]->update();
    }
}

void PlayState::render()
{
    for (int i = 0; i < mGameObjects.size(); i++)
    {
        mGameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    // load assets
    // initialise gameobjects
    return true;
}