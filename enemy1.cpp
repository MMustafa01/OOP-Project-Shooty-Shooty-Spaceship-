#include "enemy1.hpp"
// Enemy implementation will go here.
#include <iostream>

void Enemy::draw()
{ // if conditions  +
    
    if (type == "BasicEnemy1")
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy1, &srcRect, &moverRect, 0, NULL, flip);
    if (type == "BasicEnemy2")
        {
            if (flip == SDL_FLIP_NONE && moverRect.x >= 1000-50)
                flip = SDL_FLIP_HORIZONTAL;
            else if (flip == SDL_FLIP_HORIZONTAL && moverRect.x < 0)
                flip = SDL_FLIP_NONE;
            SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy2, &srcRect, &moverRect, 0, NULL, flip);
        }
    if (type == "BasicEnemy4")
        SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_enemy4, &srcRect, &moverRect, 0, NULL, flip);
}

SDL_Rect srcRect_enemy1 = {0, 3404, 1629, 1278}; // normal //BasicEnemy1 Red enemy
// SDL_Rect srcRect_enemy1 = {18, 615, 68, 70};
SDL_Rect srcRect_enemy2 = {20, 33, 598, 491};

SDL_Rect srcRect_enemy4 = {30,25,580,937};
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
    else if (type == "BasicEnemy4") // speedy rocket
    {
        srcRect = srcRect_enemy4;
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