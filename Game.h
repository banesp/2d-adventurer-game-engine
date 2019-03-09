#ifndef __GAME_H__
#define __GAME_H__

#include <vector>
#include <SDL2/SDL.h>
//#include "GameObject.h"
//#include "GameStateMachine.h"

class Game
{
  public:
    static Game *getInstance()
    {
        if (!instance)
        {
            instance = new Game();
        }

        return instance;
    }

    bool init(const char *title, int xpos, int ypos, int height, int width, int fullScreen);

    void render();
    void update();
    void handleEvents();
    void clean();
    void quit();

    bool running()
    {
        return m_bRunning;
    }

    SDL_Renderer *getRenderer() const
    {
        return m_pRenderer;
    }

    /*
    GameStateMachine *getStateMachine()
    {
        return m_pGameStateMachine;
    }
    */

  private:
    Game() {}
    ~Game() {}

    static Game *instance;

    bool m_bRunning;
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;

    int currentFrame;

    // std::vector<GameObject *> m_gameObjects;

    //GameStateMachine *m_pGameStateMachine;
};

typedef Game TheGame;

#endif
