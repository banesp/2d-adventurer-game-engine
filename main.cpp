#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include "LTexture.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
LTexture *gSpriteSheetTexture = NULL;

SDL_Rect idleClips[4];
SDL_Rect runClips[6];

enum Animation
{
    left,
    right,
    idle
};

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

    gSpriteSheetTexture = new LTexture(gRenderer);

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
    if (!gSpriteSheetTexture->loadFromFile("assets/adventurer.png"))
    {
        printf("Could not load assets/adventurer.png\n");
        return false;
    }

    // Idle
    idleClips[0].x = 0;
    idleClips[0].y = 0;
    idleClips[0].w = 50;
    idleClips[0].h = 37;

    idleClips[1].x = 50;
    idleClips[1].y = 0;
    idleClips[1].w = 50;
    idleClips[1].h = 37;

    idleClips[2].x = 100;
    idleClips[2].y = 0;
    idleClips[2].w = 50;
    idleClips[2].h = 37;

    idleClips[3].x = 150;
    idleClips[3].y = 0;
    idleClips[3].w = 50;
    idleClips[3].h = 37;

    // Run
    runClips[0].x = 50;
    runClips[0].y = 37;
    runClips[0].w = 50;
    runClips[0].h = 37;

    runClips[1].x = 100;
    runClips[1].y = 37;
    runClips[1].w = 50;
    runClips[1].h = 37;

    runClips[2].x = 150;
    runClips[2].y = 37;
    runClips[2].w = 50;
    runClips[2].h = 37;

    runClips[3].x = 200;
    runClips[3].y = 37;
    runClips[3].w = 50;
    runClips[3].h = 37;

    runClips[4].x = 250;
    runClips[4].y = 37;
    runClips[4].w = 50;
    runClips[4].h = 37;

    runClips[5].x = 300;
    runClips[5].y = 37;
    runClips[5].w = 50;
    runClips[5].h = 37;

    return true;
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
            SDL_Event e;
            int frame = 0;
            Animation anim = idle;

            while (!quit)
            {
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                SDL_RenderClear(gRenderer);

                while (SDL_PollEvent(&e) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                    else if (e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_RIGHT:
                            anim = right;
                            break;
                        case SDLK_LEFT:
                            anim = left;
                            break;
                        }
                    }
                    else
                    {
                        anim = idle;
                    }
                }

                SDL_Rect *currentClip = NULL;
                switch (anim)
                {
                case right:
                    currentClip = &runClips[frame / 4];
                    gSpriteSheetTexture->render(0, 0, currentClip);
                    break;
                case left:
                    currentClip = &runClips[frame / 4];
                    gSpriteSheetTexture->render(0, 0, currentClip, 0.0, NULL, SDL_FLIP_HORIZONTAL);
                    break;
                case idle:
                    currentClip = &idleClips[0];
                    gSpriteSheetTexture->render(0, 0, currentClip);
                    break;
                }

                SDL_RenderPresent(gRenderer);

                ++frame;
                if (frame / 4 >= 4)
                {
                    frame = 0;
                }
            }
        }
    }

    close();

    return 0;
}