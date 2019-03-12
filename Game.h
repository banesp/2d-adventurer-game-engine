#ifndef __GAME_H__
#define __GAME_H__

#include "GameObject.h"
#include "GameStateMachine.h"
#include <SDL2/SDL.h>
#include <vector>

class Game
{
public:
  static Game *getInstance()
  {
    if (!s_pInstance)
    {
      s_pInstance = new Game();
    }

    return s_pInstance;
  }

  bool init(const char *title, int xpos, int ypos, int height, int width, int fullscreen);

  void render();
  void update();
  void handleEvents();
  void clean();

  SDL_Renderer *getRenderer() const { return m_pRenderer; }
  SDL_Window *SDL_GetWindow() const { return m_pWindow; }
  GameStateMachine *getStateMachine() { return m_pGameStateMachine; }

  void setPlayerLives(int lives) { m_playerLives = lives; }
  int getPlayerLives() { return m_playerLives; }

  void setCurrentLevel(int currentLevel); // { m_currentLevel = currentLevel; }
  const int getCurrentLevel() { return m_currentLevel; }

  void setNextLevel(int nextLevel) { m_nextLevel = nextLevel; }
  const int getNextLevel() { return m_nextLevel; }

  void setLevelComplete(int levelComplete) { m_bLevelComplete = levelComplete; }
  const int getLevelComplete() { return m_bLevelComplete; }

  bool running() { return m_bRunning; }

  void quit() { m_bRunning = false; }

  int getGameWidth() const { return m_gameWidth; }
  int getGameHeight() const { return m_gameHeight; }
  float getScrollSpeed() { return m_scrollSpeed; }

  bool changingState() { return m_bChangingState; }
  void changingState(bool cs) { m_bChangingState = cs; }

private:
  static Game *s_pInstance;

  bool m_bChangingState;

  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;

  GameStateMachine *m_pGameStateMachine;

  bool m_bRunning;
  int m_gameWidth;
  int m_gameHeight;
  float m_scrollSpeed;

  int m_playerLives;

  int m_currentLevel;
  int m_nextLevel;
  bool m_bLevelComplete;

  std::vector<std::string> m_levelFiles;

  Game() : m_pWindow(0),
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

  ~Game()
  {
    m_pRenderer = 0;
    m_pWindow = 0;
  }

  Game(const Game &);
  Game &operator=(const Game &);
};

typedef Game TheGame;

#endif
