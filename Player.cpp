#include "Player.h"

Player::Player(SDL_Renderer *renderer)
{
    mTexture = new LTexture(renderer);
}

Player::~Player()
{
    mTexture->free();
}

bool Player::load()
{
    return mTexture->loadFromFile("assets/adventurer");
}

void Player::render()
{
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = 50;
    rect.h = 37;
    mTexture->render(0, 0, &rect);
}

void Player::refresh()
{
    // handle input
    // need some way to set the different animations and flip the gameobject
}

void Player::clean()
{
    mTexture = NULL;
}