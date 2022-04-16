#include "Bullet.hpp"
// Bullet implementation will go here.
#include <iostream>


void Bullet::draw(){
    switch (direction)
    {
    case -1: // moving left
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect , -30, NULL, flip);
        break;
    case 0: // center
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect , 0, NULL, flip);
        break;
    case 1: // right
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect , 30, NULL, flip);
        break;
    }
    
}

// to be able to change the position of the wings for animation
SDL_Rect srcRect12 = {18,615,68,70}; // normal



void Bullet::fly(){
    // change the srcRect and moverRect
    // changing the position of wings (srcRect)
    // animation of the flying
    // actually moving the Bullet (changing moverRect)
    switch (direction)
    {
    case -1: // moves left
        moverRect.x -= 5;
        break;
    case 1: // moves right
        moverRect.x += 5;
        break;
    }
    moverRect.y -= 5;

}

Bullet::Bullet(){
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = srcRect12;

    // it will display Bullet on x = 30, y = 40 location, the size of Bullet is 50 width, 60 height
    moverRect = {400, 500, 50, 50};
}

Bullet::Bullet(int x, int y, int z) : srcRect(srcRect12),moverRect({x+15, y, 20, 20}),direction(z) {};// constructor of Bullet with coordinates of location clicked


int Bullet::getLocation()
{
    return moverRect.y;
}