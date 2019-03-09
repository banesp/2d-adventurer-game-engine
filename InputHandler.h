#ifndef __INPUT_HANDLER__
#define __INPUT_HANDLER__

#include <SDL2/SDL.h>
#include "Vector2D.h"
#include <vector>

class InputHandler
{
public:
  static InputHandler *getInstance()
  {
    if (!instance)
    {
      instance = new InputHandler();
    }

    return instance;
  }

  void update();
  void clean();

  void initialiseJoysticks();
  bool joysticksInitialised()
  {
    return m_bJoysticksInitialised;
  }

  bool getButtonState(int joy, int buttonNumber)
  {
    return m_buttonStates[joy][buttonNumber];
  }

  bool getMouseButtonState(int buttonNumber)
  {
    return m_mouseButtonStates[buttonNumber];
  }

  bool isKeyDown(SDL_Scancode key);

  Vector2D *getMousePosition()
  {
    return m_mousePosition;
  }

  int xvalue(int joy, int stick);
  int yvalue(int joy, int stick);

private:
  InputHandler();
  ~InputHandler();

  static InputHandler *instance;

  std::vector<std::vector<bool> > m_buttonStates;

  std::vector<bool> m_mouseButtonStates;

  std::vector<std::pair<Vector2D *, Vector2D *> > m_joystickValues;
  std::vector<SDL_Joystick *> m_joysticks;

  Vector2D *m_mousePosition;

  Uint8 *m_keystates;

  bool m_bJoysticksInitialised;
  const int m_joystickDeadZone = 10000;

  // Handle keyboard events
  void onKeyUp();
  void onKeyDown();

  // Handle mouse events
  void onMouseMove(SDL_Event &event);
  void onMouseButtonDown(SDL_Event &event);
  void onMouseButtonUp(SDL_Event &event);

  // Handle joysticks events
  void onJoystickAxisMove(SDL_Event &event);
  void onJoystickButtonDown(SDL_Event &event);
  void onJoystickButtonUp(SDL_Event &event);
};

enum mouse_buttons
{
  LEFT = 0,
  MIDDLE = 1,
  RIGHT = 2
};

typedef InputHandler TheInputHandler;

#endif