#include <SDL.h>
#include "drawing.hpp"
class spaceship
{
public:
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    int health = 4;

public:
    // add the fly function here as well.
    void draw();
    void fly(int);
    spaceship();
    // may add other overloaded constructors here...
    spaceship(int, int);
    void shoot();
    void reduce_health();
    bool is_dead();
    int getLocation_x();
    int getLocation_y();
    int direction_spaceship();
    void reset_health();
};
