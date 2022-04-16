#include "spaceship.hpp"
// spaceship implementation will go here.
#include <iostream>
#include<vector>
void spaceship::draw(){
    // here we include the flipping of the spaceship
    // only chaning the flip at 2 conditions
    SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect , 0, NULL, flip);
}

// to be able to change the position of the wings for animation
SDL_Rect srcRect1 = {18,615,68,70}; // normal
SDL_Rect srcRect2 = {123,516,68,68}; // left
SDL_Rect srcRect3 = {114,617,68,68}; // right


void spaceship::fly(int key){
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
    // boundaries for the game  
    if (moverRect.x == 0 and key < 0)
    {
    }
    else if (moverRect.x == 950 and key > 0)
    {
    }
    else
        // actually moving the spaceship (changing moverRect)
        moverRect.x += key;


}

spaceship::spaceship(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = {18,615,68,70};

    // it will display spaceship on x = 30, y = 40 location, the size of spaceship is 50 width, 60 height
    moverRect = {400, 500, 50, 50};
}

spaceship::spaceship(int x, int y) // constructor of spaceship with coordinates of location clicked
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = srcRect1;

    // it will display spaceship on clicked x, y location, the size of spaceship is 50 width, 60 height
    moverRect = {400, 500, 50, 50};
}


int spaceship::getLocox()
{
    return moverRect.x;
}

int spaceship::getLocoy()
{
    return moverRect.y;
}

int spaceship::direction_spaceship() // direction signifies if it goes left (-1), straight up (0), right(1)
{
    if (SDL_RectEquals(&srcRect, &srcRect1))
    {
        return 0;
    }
    if (SDL_RectEquals(&srcRect, &srcRect2))
    {
        return -1;
    }
    if (SDL_RectEquals(&srcRect, &srcRect3))
    {
        return 1;
    }
}