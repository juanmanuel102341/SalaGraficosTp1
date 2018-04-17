#include <iostream>
#include <SDL.h>
using namespace std;
#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[]) {

	bool quit = false;
	SDL_Event event;
	SDL_Rect rect;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("tp1 sala",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface * image = SDL_LoadBMP("plane.bmp");
	//SDL_Texture *imagePng = IMG_LoadTexture(renderer, "plane2.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image);
	rect.x = 5;
	rect.y = 5;
	rect.w = 200;
	rect.h = 200;
		


	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture);
	//SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}