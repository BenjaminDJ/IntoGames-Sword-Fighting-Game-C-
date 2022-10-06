#pragma once
#include "Maths.h"


class GameObject
{
public:
	
	GameObject(int _x, int _y, int _w, int _h);

	void SetXPosition(int _x);
	int GetXPosition();

	void SetYPosition(int _y);
	int GetYPosition();

	
	int GetWidth();
	int GetHeight();


private:
	int w;
	int h;

protected:
	vec2 position;
};

