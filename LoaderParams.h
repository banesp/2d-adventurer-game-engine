#ifndef __LOADER_PARAMS_H__
#define __LOADER_PARAMS_H__

#include <iostream>

class LoaderParams
{
public:
  LoaderParams(int x, int y, int width, int height, std::string textureId) : m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureId)
  {
  }

  int getX() const { return m_x; }
  int getY() const { return m_y; }
  int getWidth() const { return m_width; }
  int getHeight() const { return m_height; }
  std::string getTextureId() const { return m_textureId; }

private:
  int m_x;
  int m_y;

  int m_width;
  int m_height;

  std::string m_textureId;
};

#endif