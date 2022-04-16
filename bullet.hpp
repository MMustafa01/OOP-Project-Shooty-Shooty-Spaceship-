#include<SDL.h>
#include "drawing.hpp"
class Bullet{

    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
public:
    // add the fly function here as well.
    void draw();
    void fly();
    Bullet(); 
    // may add other overloaded constructors here... 
    Bullet(int, int);
    int getLocation();
};