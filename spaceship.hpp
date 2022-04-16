#include <SDL.h>
#include "drawing.hpp"
class spaceship
{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

public:
    // add the fly function here as well.
    void draw();
    void fly(int);
    spaceship();
    // may add other overloaded constructors here...
    spaceship(int, int);
    void shoot();

    int getLocation_x();
    int getLocation_y();
    int direction_spaceship();
};
