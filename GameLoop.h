#pragma once

#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include <list>
#include "UI.h"
#include "Sword.h"

class GameLoop
{
public:
	void Initialise();
	void LoadContent();
	bool Update();
	void Render();
	void UnloadContent();
	void Quit();

private:
	
	// Game objects
	UI* PlayerUI;
	UI* EnemyUI;
	Player* player;
	Enemy* enemy;
	//Player* enemy;
	Sword* PlayerSword;
	Sword* EnemySword;

	// SDL pointers
	SDL_Window* window;
	SDL_Renderer* renderer;
	

	//bool once = true;

	// Game logic
	double deltaTime = 0;
	double lastFrameTime = 0;
	double currentFrameTime = 0;
};

