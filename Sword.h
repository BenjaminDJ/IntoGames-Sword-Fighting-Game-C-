#pragma once
#include "Sprite.h"
#include <string>
#include "Maths.h"
class Sword : public Sprite
{
public:
	Sword(SDL_Renderer* renderer, bool IsBlue, int AnimState, int _x, int _y);

};

