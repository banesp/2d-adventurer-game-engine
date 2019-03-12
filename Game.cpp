#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "Player.h"
#include "LoaderParams.h"
// #include "PlayState.h"
#include "MainMenuState.h"
#include <stdio.h>
#include <iostream>

Game *Game::s_pInstance = 0;

/*
Game::Game() : m_pWindow(0),
               m_pRenderer(0),
               m_bRunning(false),
               m_pGameStateMachine(0),
               m_playerLives(3),
               m_scrollSpeed(0.8),
               m_bLevelComplete(false),
               m_bChangingState(false)
{
    // Add levels
    m_levelFiles.push_back("assets/map1.tmx");
    m_levelFiles.push_back("assets/map2.tmx");

    // Set start level
    m_currentLevel = 1;
}
*/
/*
Game::~Game()
{
    m_pRenderer = 0;
    m_pWindow = 0;
}
*/

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int fullScreen)
{
    int flags = 0;

    // Store game width and height
    m_gameWidth = width;
    m_gameHeight = height;

    if (fullScreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
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

    // register game types
    // TODO: Implement gameobject factory, player, playercreator

    m_bRunning = true;

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());

    return true;
}

void Game::setCurrentLevel(int currentLevel)
{
    m_currentLevel = currentLevel;
    // m_pGameStateMachine->changeState(new GameOverState());
    m_bLevelComplete = false;
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

void Game::clean()
{
    std::cout << "Cleaning out game resources..\n";

    TheInputHandler::getInstance()->clean();

    m_pGameStateMachine = 0;
    delete m_pGameStateMachine;

    TheTextureManager::getInstance()->clearTextureMap(); // clearFromTextureMap

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();

    m_pRenderer = 0;
    m_pWindow = 0;
}
