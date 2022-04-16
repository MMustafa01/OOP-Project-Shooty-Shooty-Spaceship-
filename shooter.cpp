#include "shooter.hpp"
// Shooter implementation will go here.
#include <iostream>
#include<vector>
void Shooter::draw(){
    // here we include the flipping of the Shooter
    // only chaning the flip at 2 conditions
    SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect , 0, NULL, flip);
}

// to be able to change the position of the wings for animation
SDL_Rect srcRect1 = {18,615,68,70}; // normal
SDL_Rect srcRect2 = {123,516,68,68}; // left
SDL_Rect srcRect3 = {114,617,68,68}; // right


void Shooter::fly(int key){
    // change the srcRect and moverRect
    // changing the position of wings (srcRect)
    // animation of the flying
    if (key == 0) // if postition of wings is at the first position
    {
        srcRect = srcRect1;
    }
    else if (key < 0)
    {
        srcRect = srcRect2;
    }
    else if (key > 0)
    {
        srcRect = srcRect3;
    }
    // actually moving the Shooter (changing moverRect)
    moverRect.x += key;

}

Shooter::Shooter(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {18,615,68,70};

    // it will display Shooter on x = 30, y = 40 location, the size of Shooter is 50 width, 60 height
    moverRect = {400, 500, 50, 50};
}

Shooter::Shooter(int x, int y) // constructor of Shooter with coordinates of location clicked
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = srcRect1;

    // it will display Shooter on clicked x, y location, the size of Shooter is 50 width, 60 height
    moverRect = {400, 500, 50, 50};
}


int Shooter::getLocox()
{
    return moverRect.x;
}

int Shooter::getLocoy()
{
    return moverRect.y;
}