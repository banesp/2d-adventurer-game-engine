#include "Adventurer.h"
#include "Game.h"
#include "InputHandler.h"
#include "TileLayer.h"
#include "TextureManager.h"
#include "Camera.h"
#include <SDL2/SDL.h>
#include <iostream>

Adventurer::Adventurer() : PlatformerObject(),
                           invulnerable(false),
                           invulnerableTime(200),
                           invulnerableCounter(0),
                           state(STATE_IDLE)
{
    m_width = 100;
    m_height = 100;
}

void Adventurer::load(std::unique_ptr<LoaderParams> const &params)
{
    PlatformerObject::load(std::move(params));
}

void Adventurer::draw()
{
    TheTextureManager::getInstance()->drawFrame(
        m_textureID,
        (Uint32)m_position.getX() - TheCamera::getInstance()->getPosition().m_x,
        (Uint32)m_position.getY() - TheCamera::getInstance()->getPosition().m_y,
        m_width,
        m_height,
        m_currentRow,
        m_currentFrame,
        TheGame::getInstance()->getRenderer(),
        m_angle,
        m_alpha,
        m_bFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Adventurer::update()
{
    handleInput();

    m_velocity.m_x = 0;
    m_velocity.m_y = 0;

    handleMovement(m_velocity);
    handleAnimation();
}

void Adventurer::clean()
{
    PlatformerObject::clean();
}

void Adventurer::handleMovement(Vector2D velocity)
{
    Vector2D currentPosition = m_position;
    currentPosition.m_x = (m_position.m_x + velocity.m_x);
    m_position = currentPosition;
}

void Adventurer::handleAnimation()
{
    m_currentFrame = 0;
    m_currentRow = 0;
    m_numFrames = 1;
}

void Adventurer::handleInput()
{
    switch (state)
    {
    case STATE_IDLE:
    default:
        break;
    }
}

void Adventurer::collision()
{
}