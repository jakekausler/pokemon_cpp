#include <SDL.h>
#include <SDL_Image.h>
#include <stdio.h>
#include <stdexcept>
#include "Sprite.h"

using namespace std;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

void init() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		throw std::runtime_error("Error!");
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			throw std::runtime_error("Error!");
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				throw std::runtime_error("Error!");
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					throw std::runtime_error("Error!");
				}
			}
		}
	}
}

void tearDown() {
	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

enum Direction {
	SOUTH, WEST, EAST, NORTH
};

int main(int argc, char *argv[]) {

	//Start up SDL and create window
	init();

	Sprite sprite(gRenderer);
	sprite.LoadTexture("res/Graphics/Characters/NPC 19.png");

	const int ANIMATION_RATE = 8;
	const int TILE_WIDTH = 32;
	const int TILE_HEIGHT = 48;
	const int START_COLUMN = 0;
	const int NUM_SLIDES = 4;
	const int SPEED = 8;

	SDL_Rect viewport = { 0, 0, TILE_WIDTH, TILE_HEIGHT };

	sprite.ChangeViewport(&viewport);

	Direction direction = EAST;
	sprite.Animate(ANIMATION_RATE, TILE_HEIGHT, TILE_WIDTH, direction, START_COLUMN, NUM_SLIDES);

	SDL_Color flashColor{ 0xFF, 0x00, 0x00 };
	//sprite.Flash(&flashColor, 16);

	//Main loop flag
	bool quit = false;

	int frame = 0;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);

		frame++;

		sprite.Update();

		if (frame % ANIMATION_RATE == 0) {
			switch (direction) {
			case SOUTH:
				viewport.y += SPEED;
				if (viewport.y > SCREEN_HEIGHT - SPEED - TILE_HEIGHT + 1) {
					direction = WEST;
					sprite.Animate(ANIMATION_RATE, TILE_HEIGHT, TILE_WIDTH, direction, START_COLUMN, NUM_SLIDES);
				}
				break;
			case NORTH:
				viewport.y -= SPEED;
				if (viewport.y < SPEED) {
					direction = EAST;
					sprite.Animate(ANIMATION_RATE, TILE_HEIGHT, TILE_WIDTH, direction, START_COLUMN, NUM_SLIDES);
				}
				break;
			case EAST:
				viewport.x += SPEED;
				if (viewport.x > SCREEN_WIDTH - SPEED - TILE_WIDTH + 1) {
					direction = SOUTH;
					sprite.Animate(ANIMATION_RATE, TILE_HEIGHT, TILE_WIDTH, direction, START_COLUMN, NUM_SLIDES);
				}
				break;
			case WEST:
				viewport.x -= SPEED;
				if (viewport.x < SPEED) {
					direction = NORTH;
					sprite.Animate(ANIMATION_RATE, TILE_HEIGHT, TILE_WIDTH, direction, START_COLUMN, NUM_SLIDES);
				}
				break;
			}
		}


		//Update screen
		SDL_RenderPresent(gRenderer);
	}

	sprite.Free();

	//Free Everything
	tearDown();

	return 0;
}