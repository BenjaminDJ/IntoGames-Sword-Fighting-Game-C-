#pragma once
#include "Sprite.h"
#include <string>

class Player : public Sprite
{
public:
	Player(SDL_Renderer* renderer,
		std::string pathToSurface, bool IsBlue, int _x, int _y, int _w, int _h);

	void HandleInput(SDL_Event& e);

	void SetHealth(float newHealth);
	void ReduceHealth(float healthReduction);
	float GetHealth();

	int GetAnimState();
	void SetAnimState(int _state);
	Sprite* GetSwordSprite();
	bool IsBlocking();

	void UpdateSwordSprite();
	void ResetAttack();

private:
	float health = 100;
	float maxHealth = 100;
	float minHealth = 0;

	//Input stuff
	bool MovingRight = false;
	bool MovingLeft = false;
	bool HighStance = true;
	bool LowStance = false;
	bool Blocking = false;
	bool Attacking = false;

	//Sword stuff
	int AnimState = 0;
	std::string SwordSpritePaths[10] = {
		"assets/SwordsGame/blue/high stance.png",
		"assets/SwordsGame/blue/low stance.png",
		"assets/SwordsGame/blue/high block.png",
		"assets/SwordsGame/blue/low block.png",
		"assets/SwordsGame/blue/high attack frame 1.png",
		"assets/SwordsGame/blue/high attack frame 1.5.png", //actual frame 2
		"assets/SwordsGame/blue/high attack frame 2.png", //actual frame 3
		"assets/SwordsGame/blue/low attack frame 1.png",
		"assets/SwordsGame/blue/low attack frame 1.png", //actual frame 2
		"assets/SwordsGame/blue/low attack frame 2.png" //actual frame 3
	};
	vec2 SwordSpriteOffsets[10] = {
		vec2(-19, 22),
		vec2(12, 54),
		vec2(40, -24),
		vec2(35, 26),
		vec2(-41, -21),
		vec2(3, -63),
		vec2(50, -17),
		vec2(-76, 62),
		vec2(-39, 68), //actual frame 2
		vec2(1, 70) //actual frame 3
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
	
protected:
};

