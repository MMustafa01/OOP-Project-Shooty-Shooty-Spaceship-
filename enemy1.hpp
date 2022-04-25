#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include <iostream>
using namespace std;
class Enemy
{
protected:
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    string type;

public:
    // add the fly function here as well.
    void draw();
    virtual void fly() = 0; // make a pure virtual function

    Enemy(string t);

    // may add other overloaded constructors here...
    // Enemy(int, int, int); no need for this
    int getLocation_x();
    int getLocation_y();
    // friend void collision(&);//madse this a
};