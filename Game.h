#ifndef __GAME_H__
#define __GAME_H__

#include "GameObject.h"
#include "GameStateMachine.h"
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

    bool running()
    {
        return m_bRunning;
    }

    SDL_Renderer *getRenderer() const { return m_pRenderer; }
    SDL_Window *SDL_GetWindow() const { return m_pWindow; }
    GameStateMachine *getStateMachine() { return m_pGameStateMachine; }

  private:
    static Game *s_pInstance;

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

    Game() {}
    ~Game() {}

    Game(const Game &);
    Game &operator=(const Game &);
};

typedef Game TheGame;

#endif
