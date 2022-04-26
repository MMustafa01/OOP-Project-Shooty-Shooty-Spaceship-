#include "BasicEnemy3.hpp"
#include <iostream>
using namespace std;

BasicEnemy3::BasicEnemy3() : Enemy("BasicEnemy3") {}

void BasicEnemy3::fly()
{
    // if (flip == SDL_FLIP_NONE)
    //     {
    //         moverRect.x += 4;
    //     }    
    // else if (flip == SDL_FLIP_HORIZONTAL)
    //     {
    //         moverRect.x -= 4; // moving backwards
            
    //     }
        moverRect.y += 5;
}