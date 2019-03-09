#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "Player.h"
#include "InputHandler.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

InputHandler *gInputHandler = NULL;

Player *player = NULL;

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Could not initialise SDL. SDL Error: %s\n", SDL_GetError());
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        printf("Could not initialize SDL_image. SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    gWindow = SDL_CreateWindow("Adventurer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
        printf("Could not initialize window. SDL Error: %s\n", SDL_GetError());
        return false;
    }

    // Create a renderer using hardware acceleration and VSync
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL)
    {
        printf("Could not initialize renderer. SDL Error: %s\n", SDL_GetError());
        return false;
    }

    player = new Player(gRenderer);

    // Set initial renderer draw color
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}

void close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);

    gWindow = NULL;
    gRenderer = NULL;

    IMG_Quit();
    SDL_Quit();
}

bool load()
{
    return player->load();
}

int main(int argc, char *args[])
{
    printf("Starting adventurer..\n");

    if (init())
    {
        printf("Game initialized successfully!\n");
        if (!load())
        {
            printf("Could not load assets\n");
        }
        else
        {
            bool quit = false;

            while (!quit)
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                // player->update();
                // player->render();

                SDL_RenderPresent(gRenderer);
            }
        }
    }

    close();

    return 0;
}