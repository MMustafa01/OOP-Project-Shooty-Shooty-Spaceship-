#include <SDL.h>
#include "drawing.hpp"
class Enemy
{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

public:
    // add the fly function here as well.
    void draw();
    void fly();
    Enemy();

    // may add other overloaded constructors here...
    // Enemy(int, int, int); no need for this
    int getLocation_x();
    int getLocation_y();
};