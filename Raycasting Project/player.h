#include <SDL.h>

class Player {
	
private:

	SDL_Rect rect;

public:

	Player(const int x, const int y, const int w, const int h) {
		this->rect.x = x;
		this->rect.y = y;
		this->rect.w = w;
		this->rect.h = h;
	}

	void setPosition(const int x, const int y) {
		this->rect.x = x;
		this->rect.y = y;
	}

	void drawPlayer(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &this->rect);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
};