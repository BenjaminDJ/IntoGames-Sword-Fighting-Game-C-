#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	Enemy(SDL_Renderer* renderer,
		std::string pathToSurface, bool IsBlue, int _x, int _y, int _w, int _h);

	void HandleInput(SDL_Event& e);

	void SetHealth(float newHealth);
	void ReduceHealth(float healthReduction);
	float GetHealth();

	int GetAnimState();
	void SetAnimState(int _state);
	Sprite* GetSwordSprite();
	bool IsBlocking();

private:
	float health = 100;
	float maxHealth = 100;
	float minHealth = 0;

	//Sword stuff
	int AnimState = 0;
	std::string SwordSpritePaths[10] = {
		"assets/SwordsGame/red/high stance.png",
		"assets/SwordsGame/red/low stance.png",
		"assets/SwordsGame/red/high block.png",
		"assets/SwordsGame/red/low block.png",
		"assets/SwordsGame/red/high attack frame 1.png",
		"assets/SwordsGame/red/high attack frame 1.5.png", //actual frame 2
		"assets/SwordsGame/red/high attack frame 2.png", //actual frame 3
		"assets/SwordsGame/red/low attack frame 1.png",
		"assets/SwordsGame/red/low attack frame 1.png", //actual frame 2
		"assets/SwordsGame/red/low attack frame 2.png" //actual frame 3
	};
	vec2 SwordSpriteOffsets[10] = {
		vec2(19 - 39, 22),
		vec2(-12 - 39, 54),
		vec2(-40, -24),
		vec2(-35, 26),
		vec2(41 - 39, -21),
		vec2(-3 - 39, -63),
		vec2(-50 - 39, -17),
		vec2(76 - 39, 62),
		vec2(39 - 39, 68), //actual frame 2
		vec2(-46 - 39, 70) //actual frame 3
	};
	vec2 SwordSpriteHitboxes[10] = {
		vec2(83, 11),
		vec2(79, 27),
		vec2(40, 78),
		vec2(37, 80),
		vec2(86, 48),
		vec2(63, 77),
		vec2(81, 56),
		vec2(78, 32),
		vec2(78, 32), //actual frame 2
		vec2(127, 15), //actual frame 3
	};
	Sprite* ActiveSwordSprite = new Sprite(
		renderer, SwordSpritePaths[AnimState],
		this->GetXPosition() + SwordSpriteOffsets[AnimState].GetX(),
		this->GetYPosition() + SwordSpriteOffsets[AnimState].GetY(),
		SwordSpriteHitboxes[AnimState].GetX(),
		SwordSpriteHitboxes[AnimState].GetY()
	);
	void UpdateSwordSprite();
	void ResetAttack();
protected:
};

