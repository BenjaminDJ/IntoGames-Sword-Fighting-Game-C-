#include "Sword.h"
#include <string>

/*Sword::Sword(int _state, SDL_Renderer* renderer, std::string pathToSurface, int _x, int _y, int _w, int _h) :
	Sprite(renderer, pathToSurface, _x, _y, _w, _h)
{
	state = _state;
}*/

Sword::Sword(SDL_Renderer* renderer, bool IsBlue, int AnimState, int _x, int _y)
	: Sprite(renderer, "assets/SwordsGame/red/high stance.png", _x, _y, 83, 11)
{}
