#include "Enemy.h"
Enemy::Enemy(SDL_Renderer* renderer, std::string pathToSurface, bool IsBlue, int _x, int _y, int _w, int _h) :
	//Sprite(renderer, pathToSurface, _x, _y, _w, _h)
	Player(renderer, pathToSurface, IsBlue, _x, _y, _w, _h)
{
	//UpdateSwordSprite();
}

void Enemy::HandleInput(SDL_Event& e)
{
	int positionX = this->GetXPosition();
	int RightInc = 3;
	int LeftInc = -3;
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.scancode) {
		case SDL_SCANCODE_UP:
			std::cout << "ENEMY high stance" << std::endl;
			SetAnimState(0);
			UpdateSwordSprite();
			break;

		case SDL_SCANCODE_LEFT:
			std::cout << "ENEMY moving left" << std::endl;
			ResetAttack();
			this->SetXPosition(positionX + LeftInc);
			this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + LeftInc);
			break;

		case SDL_SCANCODE_DOWN:
			std::cout << "low stance" << std::endl;
			this->AnimState = 1;
			this->UpdateSwordSprite();
			break;

		case SDL_SCANCODE_RIGHT:
			std::cout << "moving right" << std::endl;
			ResetAttack();
			this->SetXPosition(positionX + RightInc);
			this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + RightInc);
			break;

		case SDL_SCANCODE_RCTRL:
			//Attack
			switch (AnimState) {
			case 0:
				AnimState = 4;
				break;
			case 4:
				AnimState = 5;
				break;
			case 5:
				AnimState = 6;
				break;
			case 1:
				AnimState = 7;
				break;
			case 7:
				AnimState = 8;
				break;
			case 8:
				AnimState = 9;
				break;
			}
			this->UpdateSwordSprite();
			break;
		case SDL_SCANCODE_KP_0:
			//Block
			if (AnimState == 0 || AnimState == 2 || AnimState == 4 || AnimState == 5 || AnimState == 6) {
				AnimState = 2;
			}
			else if (AnimState == 1 || AnimState == 3 || AnimState == 7 || AnimState == 8 || AnimState == 9) {
				AnimState = 3;
			}
			this->UpdateSwordSprite();
			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.scancode) {

		case SDL_SCANCODE_KP_0:
			//Block
			if (AnimState == 2) {
				AnimState = 0;
			}
			else if (AnimState == 3) {
				AnimState = 1;
			}
			this->UpdateSwordSprite();
			break;
		default:
			ResetAttack();
			break;
		}
	}
}

void Enemy::SetHealth(float newHealth) {
	health = newHealth;
	if (health >= maxHealth) {
		health = maxHealth;
	}
	else if (health <= minHealth) {
		health = minHealth;
	}
}

void Enemy::ReduceHealth(float healthReduction) {

	health = health - healthReduction;
	if (health >= maxHealth) {
		health = maxHealth;
	}
	else if (health <= minHealth) {
		health = minHealth;
	}

}

float Enemy::GetHealth() {
	return health;
}

int Enemy::GetAnimState() {
	return AnimState;
}

void Enemy::SetAnimState(int _state)
{
	AnimState = _state;
}

Sprite* Enemy::GetSwordSprite()
{
	return ActiveSwordSprite;
}

bool Enemy::IsBlocking()
{
	return AnimState == 2 || AnimState == 3;
}

void Enemy::UpdateSwordSprite() {
	ActiveSwordSprite = new Sprite(
		renderer, SwordSpritePaths[AnimState],
		this->GetXPosition() + SwordSpriteOffsets[AnimState].GetX(),
		this->GetYPosition() + SwordSpriteOffsets[AnimState].GetY(),
		SwordSpriteHitboxes[AnimState].GetX(),
		SwordSpriteHitboxes[AnimState].GetY()
	);
}

void Enemy::ResetAttack() {
	if (AnimState == 6) {
		AnimState = 0;
	}
	else if (AnimState == 9) {
		AnimState = 1;
	}
	this->UpdateSwordSprite();
}
