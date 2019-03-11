#include "Game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FULLSCREEN = false;

int main(int argc, char *args[])
{
    Uint32 frameStart, frameTime;

    if (!TheGame::getInstance()->init("Adventurer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_FULLSCREEN))
    {
        printf("Initialization failed. SDL Error: %s\n", SDL_GetError());
        return -1;
    }

    printf("Initialization successful. Starting gameloop\n");
    while (TheGame::getInstance()->running())
    {
        frameStart = SDL_GetTicks();

        TheGame::getInstance()->handleEvents();
        TheGame::getInstance()->update();
        TheGame::getInstance()->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }
    }

    printf("Quiting game..\n");
    TheGame::getInstance()->clean();

    return 0;
}
