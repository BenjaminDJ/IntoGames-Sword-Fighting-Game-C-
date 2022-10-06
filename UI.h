#pragma once
#include <SDL.h>
#include "Player.h"

class UI
{
public:

	UI(SDL_Renderer* _renderer, int _x, int _y);
	void Render(int _health);
	
private:
	SDL_Renderer* renderer;
	Player* player;
	int x;
	int y;
};
