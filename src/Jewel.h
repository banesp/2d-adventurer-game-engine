#ifndef __JEWEL_H__
#define __JEWEL_H__

#include "PlatformerObject.h"
#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "GameObjectFactory.h"

class Jewel : public PlatformerObject
{
  public:
    Jewel() : PlatformerObject()
    {
    }

    virtual std::string type() { return "Jewel"; }

    virtual void update()
    {
        m_currentFrame = int(((SDL_GetTicks() / (100)) % m_numFrames));
    }

    virtual void load(std::unique_ptr<LoaderParams> const &pParams)
    {
        PlatformerObject::load(std::move(pParams));
    }

    virtual void draw()
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
            m_alpha);
    }
};

class JewelCreator : public BaseCreator
{
    GameObject *createGameObject() const
    {
        return new Jewel();
    }
};

#endif