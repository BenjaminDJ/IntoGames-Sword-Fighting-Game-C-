#include "GameObject.h"


GameObject::GameObject(int _x, int _y, int _w, int _h) :
	position(_x, _y)
{
	w = _w;
	h = _h;
}

void GameObject::SetXPosition(int _x)
{
	position.SetX(_x);
}

int GameObject::GetXPosition()
{
	return position.GetX();
}

void GameObject::SetYPosition(int _y)
{
	position.SetY(_y);
}

int GameObject::GetYPosition()
{
	return position.GetY();
}

int GameObject::GetWidth()
{
	return w;
}

int GameObject::GetHeight()
{
	return h;
}




