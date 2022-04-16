#include <SDL.h>
#pragma once
class Drawing
{
public:
    // The window renderer
    static SDL_Renderer *gRenderer;
    // global reference to png image sheets
    static SDL_Texture *assets;        // spaceship
    static SDL_Texture *assets_enemy1; // enenmy
};