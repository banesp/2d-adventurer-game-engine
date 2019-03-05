#include <SDL2/SDL.h>
#include "LTexture.h"

class Player
{
  public:
    Player(SDL_Renderer *renderer);
    ~Player();

    bool load();
    void render();
    void refresh();
    void clean();

  private:
    SDL_Renderer *mRenderer;
    LTexture *mTexture;
}