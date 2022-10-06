#include "GameLoop.h"

void GameLoop::Initialise()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return;
	}
	else {
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
			return;
		}

		window = SDL_CreateWindow("IntoGames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 256, SDL_WINDOW_SHOWN);

		if (window == NULL) {
			std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
			return;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			std::cerr << "SDL could not initialize renderer! SDL_Error: " << SDL_GetError() << std::endl;
		}
	}

}

void GameLoop::LoadContent()
{
	player = new Player(renderer, "assets/SwordsGame/blue/hitbox.png", true, 50, 100, 39, 106);

	enemy = new Enemy(renderer, "assets/SwordsGame/red/hitbox.png", false, 500, 100, 39, 106);


	PlayerUI = new UI(renderer, 10, 10);
	EnemyUI = new UI(renderer, 475, 10);
}

bool GameLoop::Update()
{
	//SDL_Delay(2);

	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {

		if (e.type == SDL_QUIT) {
			return false;
		}
		if (player->GetHealth() > 0) {
			player->HandleInput(e);
		}
		else {
			player->SetVisible(false);
			player->GetSwordSprite()->SetVisible(false);
		}
		if (enemy->GetHealth() > 0) {
			enemy->HandleInput(e);
		}
		else {
			enemy->SetVisible(false);
			enemy->GetSwordSprite()->SetVisible(false);
		}
		
	}

	


	// Update game state

	if (player->GetHealth() > 0 && enemy->GetHealth() > 0) {
		//Check swords collisions
		if (player->GetSwordSprite()->IsCollidingWith(*enemy)) {
			if (enemy->GetAnimState() == 2) {
				if (player->GetAnimState() == 0 || player->GetAnimState() == 2 || player->GetAnimState() == 4 || player->GetAnimState() == 5 || player->GetAnimState() == 6) {
					//Do nothing
				}
				else {
					enemy->ReduceHealth(0.1);
				}
			}
			else if (enemy->GetAnimState() == 3) {
				if (player->GetAnimState() == 1 || player->GetAnimState() == 3 || player->GetAnimState() == 7 || player->GetAnimState() == 8 || player->GetAnimState() == 9) {
					//Do nothing
				}
				else {
					enemy->ReduceHealth(0.1);
				}
			}
			else {
				enemy->ReduceHealth(0.1);
			}
		}
		if (enemy->GetSwordSprite()->IsCollidingWith(*player)) {
			if(player->GetAnimState() == 2) {
				if (enemy->GetAnimState() == 0 || enemy->GetAnimState() == 2 || enemy->GetAnimState() == 4 || enemy->GetAnimState() == 5 || enemy->GetAnimState() == 6) {
					//Do nothing
				}
				else if (player->GetAnimState() == 3) {
					if (enemy->GetAnimState() == 1 || enemy->GetAnimState() == 3 || enemy->GetAnimState() == 7 || enemy->GetAnimState() == 8 || enemy->GetAnimState() == 9) {
						//Do nothing
					}
					else {
						enemy->ReduceHealth(0.1);
					}
				}
				else {
					player->ReduceHealth(0.1);
				}
			}
		else {
			player->ReduceHealth(0.1);
		}
		}
	}


	// Calculate delta time.
	lastFrameTime = currentFrameTime;
	currentFrameTime = SDL_GetPerformanceCounter();
	deltaTime = (double)((currentFrameTime - lastFrameTime) / (double)SDL_GetPerformanceFrequency());


	return true;
}



void GameLoop::Render()
{
	// Change the background colour here
	SDL_SetRenderDrawColor(renderer, 60, 60, 60, 0);
	SDL_RenderClear(renderer);

	// Render any other object here.




	player->Render();
	enemy->Render();
	player->GetSwordSprite()->Render();
	enemy->GetSwordSprite()->Render();

	PlayerUI->Render(player->GetHealth());
	EnemyUI->Render(enemy->GetHealth());

	SDL_RenderPresent(renderer);
}

void GameLoop::UnloadContent()
{

}

void GameLoop::Quit()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	window = NULL;
	SDL_Quit();
}
