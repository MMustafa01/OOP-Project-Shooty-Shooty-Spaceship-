#pragma once
#include <SDL.h>
#include "drawing.hpp"
#include <iostream>
using namespace std;

class Score
{
    SDL_Rect srcRect, moverRect;
    int frame = 0;
    int the_actual_score = 0;
    
public:
    Score(int, int);
    void draw();
};