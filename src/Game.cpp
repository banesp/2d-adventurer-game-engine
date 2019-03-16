#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "LoaderParams.h"
#include "PlayState.h"
#include "ScrollingBackground.h"
#include "MainMenuState.h"
#include "MenuButton.h"
#include "Player.h"
#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "Snail.h"
#include "Jewel.h"
#include "Adventurer.h"
#include <stdio.h>
#include <iostream>

Game *Game::s_pInstance = 0;

Game::Game() : m_pWindow(0),
               m_pRenderer(0),
               m_bRunning(false),
               m_pGameStateMachine(0),
               m_playerLives(3),
               m_bLevelComplete(false),
               m_currentLevel(1)
{
    m_levelFiles.push_back("assets/map1.tmx");
}

Game::~Game()
{
    m_pRenderer = NULL;
    m_pWindow = NULL;
}

bool Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    // Store game width and height
    m_gameWidth = width;
    m_gameHeight = height;

    if (fullscreen)
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

    // Register game types
    TheGameObjectFactory::Instance()->registerType("MenuButton", new MenuButtonCreator());
    TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());
    TheGameObjectFactory::Instance()->registerType("ScrollingBackground", new ScrollingBackgroundCreator());
    TheGameObjectFactory::Instance()->registerType("Snail", new SnailCreator());
    TheGameObjectFactory::Instance()->registerType("Jewel", new JewelCreator());
    TheGameObjectFactory::Instance()->registerType("Adventurer", new AdventurerCreator());

    m_bRunning = true;

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MainMenuState());

    return true;
}

void Game::setCurrentLevel(int currentLevel)
{
    m_currentLevel = currentLevel;
    m_pGameStateMachine->changeState(new MainMenuState());
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

    TheTextureManager::getInstance()->clearTextureMap();

    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}
