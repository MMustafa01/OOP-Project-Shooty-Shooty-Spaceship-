#include<SDL.h>
#include "drawing.hpp"
class Shooter{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
public:
    // add the fly function here as well.
    void draw();
    void fly(int);
    Shooter(); 
    // may add other overloaded constructors here... 
    Shooter(int, int);
    void shoot();
    int getLocox();
    int getLocoy();
};
