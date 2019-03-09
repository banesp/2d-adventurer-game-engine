/*
#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Player.h"
#include "Enemy.h"
#include "MenuState.h"
#include "PlayState.h"

Game *Game::instance = 0;

void Game::quit()
{
    std::cout << "Ending game.." << std::endl;
    SDL_Quit();
}

bool Game::init(const char *title, int xpos, int ypos, int height, int width, int fullScreen)
{
    int flags = SDL_WINDOW_SHOWN;

    if (fullScreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_pWindow = SDL_CreateWindow(title, xpos, ypos, height, width, flags);
    if (!m_pWindow)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    if (!m_pRenderer)
    {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

    TheInputHandler::getInstance()->initialiseJoysticks();
    TheTextureManager::getInstance()->load("assets/animate-alpha.png", "animate", m_pRenderer);

    Player *player = new Player(new LoaderParams(100, 100, 128, 82, "animate"));
    Enemy *enemy = new Enemy(new LoaderParams(300, 300, 128, 82, "animate"));

    m_gameObjects.push_back(player);
    m_gameObjects.push_back(enemy);

    m_bRunning = true;

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    // m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents()
{
    TheInputHandler::getInstance()->update();
}

void Game::update()
{
    // m_pGameStateMachine->update();
}

void Game::clean()
{
    TheInputHandler::getInstance()->clean();

    m_bRunning = false;

    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
    SDL_Quit();
}
*/