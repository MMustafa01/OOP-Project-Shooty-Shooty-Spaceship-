#include "Coin.hpp"
SDL_Rect src_coin1 = {277,21,22,22};
SDL_Rect src_coin2 = {343,20,18,22};
SDL_Rect src_coin3 = {408, 19, 16, 22};
SDL_Rect src_coin4 = {474, 20, 12, 22};
SDL_Rect src_coin5 = {540, 21, 8, 22};
SDL_Rect src_coin6 = {602, 20, 12, 22};
SDL_Rect src_coin7 = {664, 19, 16, 22};
SDL_Rect src_coin8 = {727,20,18,22};
SDL_Rect src_coin9 = {789,21,22,22};

Coin::Coin()
{
    srcRect = src_coin1;
    int rand_position = rand() % 949;
    moverRect = {rand_position, -5, 12, 12};
}

void Coin::fly()
{
    int switcher = frame%18;
    switcher = switcher/2;
    switch (switcher)// from 0 to 8
    { 
        case (0) :
        {
            srcRect = src_coin1;
            break;
        }
        case (1) :
        {
            srcRect = src_coin2;
            break;
        }
        case (2) :
        {
            srcRect = src_coin3;
            break;
        }
        case (3) :
        {
            srcRect = src_coin4;
            break;
        }
        case (4) :
        {
            srcRect = src_coin5;
            break;
        }
        case (5) :
        {
            srcRect = src_coin6;
            break;
        }
        case (6) :
        {
            srcRect = src_coin7;
            break;
        }
        case (7) :
        {
            srcRect = src_coin8;
            break;
        }
        case (8) :
        {
            srcRect = src_coin9;
            break;
        }
    }
    frame++;
    moverRect.y += 2;
}

void Coin::draw()
{
    moverRect.w = srcRect.w / 2;
    moverRect.h = srcRect.h / 2;
    SDL_RenderCopyEx(Drawing::gRenderer, Drawing::assets_coin, &srcRect, &moverRect, 0, NULL, flip);
}

int Coin::getLocation_x()
{
    return moverRect.x;
}

int Coin::getLocation_y()
{
    return moverRect.y;
}