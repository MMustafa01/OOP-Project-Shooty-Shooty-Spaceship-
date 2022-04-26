#include "BasicEnemy2.hpp"
#include <iostream>
using namespace std;

BasicEnemy2::BasicEnemy2() : Enemy("BasicEnemy2") {}

void BasicEnemy2::fly()
{
    if (flip == SDL_FLIP_NONE)
        {
            moverRect.x += 4;
        }    
    else if (flip == SDL_FLIP_HORIZONTAL)
        {
            moverRect.x -= 4; // moving backwards
            
        }
        moverRect.y += 5;
}