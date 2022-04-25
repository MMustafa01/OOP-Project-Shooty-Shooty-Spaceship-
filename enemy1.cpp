#include "enemy1.hpp"
// Enemy implementation will go here.
#include <iostream>

void Enemy::draw()
{ // if conditions  +
    if (type == "BasicEnemy1")
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy1, &srcRect, &moverRect, 0, NULL, flip);
    if (type == "BasicEnemy2")
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy2, &srcRect, &moverRect, 0, NULL, flip);
}

SDL_Rect srcRect_enemy1 = {0, 3404, 1629, 1278}; // normal //BasicEnemy1 Red enemy
// SDL_Rect srcRect_enemy1 = {18, 615, 68, 70};
SDL_Rect srcRect_enemy2 = {18, 18, 55, 77};
// void Enemy::fly()
// {
//     // actually moving the enemy ship (changing moverRect
//     moverRect.y += 5;
// }
Enemy::Enemy(string t) : type(t)
{
    if (type == "BasicEnemy1") // Red enemy
    {
        srcRect = srcRect_enemy1;
    }
    else if (type == "BasicEnemy2") // eater of worlds
    {
        srcRect = srcRect_enemy2;
    }
    int rand_position = rand() % 949;        // in the range 0 to 950
    moverRect = {rand_position, -5, 50, 50}; // make this the same for all
}

int Enemy::getLocation_y()
{
    return moverRect.y;
}

int Enemy::getLocation_x()
{
    return moverRect.x;
}