#include "UI.h"

UI::UI(SDL_Renderer* _renderer, int _x, int _y) {
	renderer = _renderer;
	x = _x;
	y = _y;
}

void UI::Render(int _health)
{
	int health = _health;
	float relativeHealth = (float)health;
	relativeHealth = relativeHealth / 100;

	int greenBarWidth = (int)(150 * relativeHealth);

	// Drawing a red bar
	//								 R    G  B  A
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect redBarRectangle;
	redBarRectangle.x = x;
	redBarRectangle.y = y;
	redBarRectangle.w = 150;
	redBarRectangle.h = 20;
	SDL_RenderFillRect(renderer, &redBarRectangle);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_Rect greenBarRectangle;
	greenBarRectangle.x = x;
	greenBarRectangle.y = y;
	greenBarRectangle.w = greenBarWidth;
	greenBarRectangle.h = 20;
	SDL_RenderFillRect(renderer, &greenBarRectangle);

}