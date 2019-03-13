#include <iostream>
#include "PlayState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "Game.h"
#include "InputHandler.h"
#include "LevelParser.h"
#include "Level.h"
#include "TextureManager.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    if (m_loadingComplete && !m_exiting)
    {
        if (TheInputHandler::getInstance()->isKeyDown(SDL_SCANCODE_ESCAPE))
        {
            TheGame::getInstance()->getStateMachine()->pushState(new PauseState());
        }

        //        if(TheInputHandler::Instance()->getButtonState(0, 8))
        //        {
        //            TheGame::Instance()->getStateMachine()->pushState(new PauseState());
        //        }

        if (TheGame::getInstance()->getPlayerLives() == 0)
        {
            TheGame::getInstance()->getStateMachine()->changeState(new GameOverState());
        }

        if (pLevel != 0)
        {
            pLevel->update();
        }
    }
}

void PlayState::render()
{
    if (m_loadingComplete)
    {
        if (pLevel != 0)
        {
            pLevel->render();
        }

        for (int i = 0; i < TheGame::getInstance()->getPlayerLives(); i++)
        {
            TheTextureManager::getInstance()->drawFrame("lives", i * 30, 0, 32, 30, 0, 0, TheGame::getInstance()->getRenderer(), 0.0, 255);
        }
    }
}

bool PlayState::onEnter()
{
    TheGame::getInstance()->setPlayerLives(3);

    LevelParser levelParser;
    pLevel = levelParser.parseLevel(TheGame::getInstance()->getLevelFiles()[TheGame::getInstance()->getCurrentLevel() - 1].c_str());

    if (pLevel != 0)
    {
        m_loadingComplete = true;
    }

    std::cout << "entering PlayState\n";

    return true;
}

bool PlayState::onExit()
{
    m_exiting = true;

    TheInputHandler::getInstance()->reset();

    std::cout << "exiting PlayState\n";

    return true;
}
