#include "Sprite.h"


Sprite::Sprite(SDL_Renderer* sdlRenderer, std::string pathToSurface, int _x, int _y, int _w, int _h) 
	: renderer(sdlRenderer), GameObject(_x, _y, _w, _h)
{
	SDL_Surface* surface = IMG_Load(pathToSurface.c_str());

	if (surface == NULL) {
		std::cerr << "Could not load surface at path: " << pathToSurface << std::endl;
		return;
	}

	visible = true;

	texture = SDL_CreateTextureFromSurface(renderer, surface);
	
	SDL_FreeSurface(surface);

}




bool Sprite::IsCollidingWith(Sprite& otherSprite)
{
	
	bool collision = SDL_HasIntersection(&collisionRect,
					&otherSprite.collisionRect);


	return collision;
}



void Sprite::Render() {

	if (this->visible) {


		destinationRect.x = this->GetXPosition();
		destinationRect.y = this->GetYPosition();
		destinationRect.h = this->GetHeight();
		destinationRect.w = this->GetWidth();

		collisionRect.x = destinationRect.x;
		collisionRect.y = destinationRect.y;
		collisionRect.h = destinationRect.h;
		collisionRect.w = destinationRect.w;

		SDL_RenderCopy(renderer, texture, NULL, &destinationRect);
		SDL_RenderDrawRect(renderer, &collisionRect);
	}
}


