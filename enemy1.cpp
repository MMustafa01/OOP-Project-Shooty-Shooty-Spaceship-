#include "enemy1.hpp"
// Enemy implementation will go here.
#include <iostream>

void Enemy::draw()
{
    SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy1, &srcRect, &moverRect, 0, NULL, flip);
}

SDL_Rect srcRect_enemy1 = {0, 3404, 1629, 1278}; // normal
// SDL_Rect srcRect_enemy1 = {18, 615, 68, 70};

void Enemy::fly()
{
    // actually moving the enemy ship (changing moverRect
    moverRect.y += 5;
    if (moverRect.y > 600)
    {
        moverRect.y = 0;
    }
}

Enemy::Enemy()
{
    // src coorinates from assets.png file, they have been found using spritecow.com
    srcRect = srcRect_enemy1;

    // it will display Bullet on x =400 , y =0 location, the size of enemy ship is 50 width, 60 height
    moverRect = {400, 0, 50, 50};
}

Enemy::Enemy(int x, int y) : srcRect(srcRect_enemy1), moverRect({x + 15, y, 50, 50}){}; // constructor of Bullet with coordinates of location clicked

int Enemy::getLocation()
{
    return moverRect.y;
}