#include <SDL.h>
#pragma once
class Drawing
{
public:
    // The window renderer
    static SDL_Renderer *gRenderer;
    static SDL_Renderer *gRenderer_start_srceen;
    static SDL_Renderer *gRenderer_lava_bg;  // first bg
    static SDL_Renderer *gRenderer_gameover; // second bg
    // global reference to png image sheets
    static SDL_Texture *assets;        // spaceship
    static SDL_Texture *assets_enemy1; // enenmy
    static SDL_Texture *assets_enemy2; // enemy 2 basic
};