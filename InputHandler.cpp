#include "InputHandler.h"

InputHandler *InputHandler::sInstance = 0;

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if (mKeyStates == 0)
    {
        return true;
    }

    return mKeyStates[key] == 1;
}

void InputHandler::onKeyDown()
{
    mKeyStates = (Uint8 *)SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp()
{
    mKeyStates = (Uint8 *)SDL_GetKeyboardState(0);
}

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            // TheGame quit
            break;
        case SDL_KEYDOWN:
            onKeyDown();
            break;
        case SDL_KEYUP:
            onKeyUp();
            break;
        default:
            break;
        }
    }
}
