#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "LoaderParams.h"
#include "PlayState.h"
#include <stdio.h>

Game *Game::instance = 0;

/**
 * Note to self
 * Might want to remove assetloading and 
 * gameobject initialization to the actual state they are used.
 */
bool Game::init(const char *title, int xpos, int ypos, int width, int height, int fullScreen)
{
    int flags = SDL_WINDOW_SHOWN;
    if (fullScreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL_Init error: %s\n", SDL_GetError());
        return false;
    }

    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (!m_pWindow)
    {
        printf("SDL_CreateWindow error: %s\n", SDL_GetError());
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if (!m_pRenderer)
    {
        printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
        return false;
    }

    //TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", m_pRenderer);
    TheInputHandler::getInstance()->initialiseJoysticks();

    //Player *player = new Player(new LoaderParams(100, 100, 128, 82, "animate"));

    //m_gameObjects.push_back(player);

    m_bRunning = true;

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new PlayState());

    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

    return true;
}

void Game::handleEvents()
{
    TheInputHandler::getInstance()->update();
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);
    m_pGameStateMachine->render();
    SDL_RenderPresent(m_pRenderer);
}

void Game::quit()
{
    clean();
}

void Game::clean()
{
    TheInputHandler::getInstance()->clean();

    m_bRunning = false;

    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
