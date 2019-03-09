#ifndef __INPUTHANDLER_H__
#define __INPUTHANDLER_H__

#include <SDL2/SDL.h>
#include <vector>

class InputHandler
{
public:
  static InputHandler *getInstance()
  {
    if (!sInstance)
    {
      sInstance = new InputHandler();
    }

    return sInstance;
  }

  void update();
  void clean();

  bool isKeyDown(SDL_Scancode key);

  bool getButtonState(int joy, int buttonNumber)
  {
    return mButtonStates[joy][buttonNumber];
  }

private:
  InputHandler();
  ~InputHandler();

  static InputHandler *sInstance;

  Uint8 *mKeyStates;
  std::vector<std::vector<bool> > mButtonStates;

  // Handle keyboard events
  void onKeyUp();
  void onKeyDown();
};

typedef InputHandler TheInputHandler;

#endif