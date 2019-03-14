#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Vector2D.h"
#include <iostream>

class Camera
{
  public:
    static Camera *getInstance()
    {
        if (!s_pCamera)
        {
            s_pCamera = new Camera();
        }

        return s_pCamera;
    }

    void update(Vector2D velocity);
    void setTarget(Vector2D *target) { m_pTarget = target; }
    void setPosition(const Vector2D &position) { m_position = position; }

    const Vector2D getPosition() const;

  private:
    static Camera *s_pCamera;

    Vector2D *m_pTarget;
    Vector2D m_position;

    Camera();
    ~Camera();
};

typedef Camera TheCamera;

#endif