#include<SDL.h>
#include "drawing.hpp"
class Bullet{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    int direction = 0; // direction signifies if it goes left (-1), straight up (0), right(1)
public:
    // add the fly function here as well.
    void draw();
    void fly();
    Bullet(); 
    // may add other overloaded constructors here... 
    Bullet(int, int, int);
    int getLocation_x();
    int getLocation_y();
};