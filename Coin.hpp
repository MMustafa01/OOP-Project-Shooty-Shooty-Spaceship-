#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include <iostream>
using namespace std;

class Coin
{
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
public:
    Coin();
    void draw();
    void fly();
    int getLocation_x();
    int getLocation_y();
};