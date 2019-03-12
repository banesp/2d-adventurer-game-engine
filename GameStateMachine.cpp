#include "GameStateMachine.h"
#include <stdio.h>

void GameStateMachine::pushState(GameState *pState)
{
    mGameStates.push_back(pState);
    mGameStates.back()->onEnter();
}

void GameStateMachine::changeState(GameState *pState)
{
    if (!mGameStates.empty())
    {
        if (mGameStates.back()->getStateID() != pState->getStateID())
        {
            if (mGameStates.back()->onExit())
            {
                delete mGameStates.back();
                mGameStates.pop_back();
            }
        }
    }

    // Push new state to back
    mGameStates.push_back(pState);
    mGameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if (!mGameStates.empty())
    {
        if (mGameStates.back()->onExit())
        {
            delete mGameStates.back();
            mGameStates.pop_back();
        }
    }
}

void GameStateMachine::update()
{
    printf("GameStateMachine::update\n");
    if (!mGameStates.empty())
    {
        printf("GameStateMachine::update is not empty!\n");
        mGameStates.back()->render();
    }
}

void GameStateMachine::render()
{
    if (!mGameStates.empty())
    {
        mGameStates.back()->render();
    }
}