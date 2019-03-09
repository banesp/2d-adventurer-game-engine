#include "Game.h"
#include <SDL2/SDL.h>
#include <stdio.h>

const int FRAMES_PER_SECOND = 60;
const int DELAY_TIME = 1000.0f / FRAMES_PER_SECOND;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[])
{
    printf("Starting up adventurer..\n");
    Uint32 frameStart, frameTime;
    Game *game = TheGame::getInstance();

    if (!game->init("Adventurer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false))
    {
        printf("Could not initialize game\n");
        return -1;
    }

    printf("Game successfully initialized\n");

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameTime < DELAY_TIME)
        {
            SDL_Delay((int)(DELAY_TIME - frameTime));
        }

        printf("End of game loop\n");
    }

    game->clean();

    return 0;
}
