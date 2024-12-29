#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "player.h"

using namespace std;

void fixAngle(double* angle) {
	if (*angle < -M_PI * 2) {
		*angle += M_PI * 2;
	}
	else if (*angle > M_PI * 2) {
		*angle -= M_PI * 2;
	}
}

int main(int argc, char* argv[]) {

	Player* player = new Player(10, 10, 10, 10);

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Raycasting", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 500, 0);
	
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	short close = 0;
	while (!close) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				close = 1;
				break;
			}
		}
		SDL_RenderClear(renderer);
		// TODO: Draw here
		player->drawPlayer(renderer);
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	delete player;
	SDL_Quit();
	return 0;
}