#include "game.hpp"
#include "Frame.hpp"
#include "drawing.hpp"

#include <cmath>

SDL_Renderer *Drawing::gRenderer = NULL;
// SDL_Renderer *Drawing::gRenderer_gos = NULL; // gameoverscreen
SDL_Texture *Drawing::assets = NULL;
SDL_Texture *Drawing::assets_enemy1 = NULL;
// SDL_Texture *Drawing::game_over_screen = NULL;
int screen = 0; // initial screen

bool Game::init()
{
	// Initialization flag
	bool success = true;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		// Create window
		gWindow = SDL_CreateWindow("Shooty Shooty Spaceship", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			// Create renderer for window
			Drawing::gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (Drawing::gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				// Initialize renderer color
				SDL_SetRenderDrawColor(Drawing::gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				// Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Game::loadMedia()
{
	// Loading success flag
	bool success = true;

	// loading alll png
	// first laod in drawing.hpp then here
	Drawing::assets = loadTexture("assets_project.png");
	Drawing::assets_enemy1 = loadTexture("ship.png");

	gTexture = loadTexture("lava bg.png"); // The background is loaded here
	// gTexture = loadTexture("initial screen.png");
	if (Drawing::assets == NULL || gTexture == NULL)
	{
		printf("Unable to run due to error: %s\n", SDL_GetError());
		success = false;
	}
	return success;
}

void Game::close()
{
	// Free loaded images
	SDL_DestroyTexture(Drawing::assets);
	Drawing::assets = NULL;

	SDL_DestroyTexture(Drawing::assets_enemy1);
	Drawing::assets_enemy1 = NULL;

	SDL_DestroyTexture(gTexture);

	// Destroy window
	SDL_DestroyRenderer(Drawing::gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	Drawing::gRenderer = NULL;
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture *Game::loadTexture(std::string path)
{
	// The final texture
	SDL_Texture *newTexture = NULL;

	// Load image at specified path
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		// Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(Drawing::gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		// Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Game::run()
{
	bool quit = false;
	SDL_Event e;

	Frame Frame;

	// A temporary solution to multiple spaceships
	unsigned int last_time = SDL_GetTicks(), current_time;

	unsigned int last_time_for_enemy1 = SDL_GetTicks(), current_time_for_enemy1; // same thing we did for bullets but this time we do for enemies

	while (!quit)
	{
		// sample coed, does not work as expected
		int movement = 0;
		/*
		Uint8* keystate = SDL_GetKeyboardState(NULL);

		//continuous-response keys
		if(keystate[SDLK_LEFT]){}
		if(keystate[SDLK_RIGHT]){}
		if(keystate[SDLK_UP]){}
		if(keystate[SDLK_DOWN]){}*/

		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{

			if (screen == 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				gTexture = loadTexture("initial screen.png");
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse, &yMouse);
					std::cout << "Mouse clicked at: " << xMouse << " -- " << yMouse << std::endl;
					if (370 <= xMouse and xMouse <= 627 and 371 <= yMouse and yMouse <= 422)
					{

						gTexture = loadTexture("choose screen.png");
						screen = 1;
					}
				}
			}

			if (Frame.the_actual_spaceship.is_dead())
			{
				screen = 6;
				gTexture = loadTexture("game over screen.png");
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse, &yMouse);
					std::cout << "Mouse clicked at: " << xMouse << " -- " << yMouse << std::endl;
					if (298 <= xMouse and xMouse <= 702 and 428 <= yMouse and yMouse <= 473)
					{
						cout << "working" << endl;

						// the_actual_spaceship.changehealth(4);
						// health = 4;
						// Frame.resets_health();

						// Frame.resets_health(the_actual_spaceship &);
						Frame.resets_health();

						// this part isnt working cuz idhar aa kar screen stops cuz the spaceship is dead wali condition is still tru
						// so what w need to do is reset th health to 4 BUT i legit cant figure that part out

						screen = 0;
					}
				}
			}

			// int count =0;
			// count ++ ;
			// cout << count << "\n";

			// for the enemy1 class to stop it from being a continuous line
			if (screen == 1)
			{

				current_time_for_enemy1 = SDL_GetTicks();
				if (current_time_for_enemy1 > last_time_for_enemy1 + 5000 / pow(2, current_time_for_enemy1 / 100000) + 100) // change this to a varible
				{
					Frame.createObject();
					last_time_for_enemy1 = current_time_for_enemy1;
				}

				// User requests quit
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}

				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					int xMouse, yMouse;
					SDL_GetMouseState(&xMouse, &yMouse);
					Frame.createObject(xMouse, yMouse);
				}
				// here is keyboard input

				if (e.key.keysym.sym == SDLK_RIGHT)
				{
					movement = 8;
					// Frame.drawObjects(8); // For movement towardsright.
					// Not an efficient method, as the game would draw objects twice
				}
				if (e.key.keysym.sym == SDLK_LEFT)
				{
					movement = -8;
					// Frame.drawObjects(-8); // For movement towards left
				}
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.sym == SDLK_UP)
					{
						current_time = SDL_GetTicks();
						if (current_time > last_time + 500 / pow(2, current_time_for_enemy1 / 100000) + 100) // speeds up after every 100 seconds
						{
							Frame.shootytime();
							last_time = current_time;
						}
					}
				}
			}
		}

		SDL_RenderClear(Drawing::gRenderer);					  // removes everything from renderer
		SDL_RenderCopy(Drawing::gRenderer, gTexture, NULL, NULL); // Draws background to renderer
																  //********draw the objects here*******
		if (screen == 1)
		{
			Frame.drawObjects(movement); // movement variable denotes the movement of the spaceship. It becomes zero in every loop, and becomes 8 or -8 if the arrow keys are pressed
		}
		//**********************
		SDL_RenderPresent(Drawing::gRenderer); // displays the updated renderer

		SDL_Delay(50); // causes sdl engine to delay for specified miliseconds
	}
}