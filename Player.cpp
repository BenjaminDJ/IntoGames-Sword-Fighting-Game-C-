#include "Player.h"

Player::Player(SDL_Renderer* renderer, std::string pathToSurface, bool IsBlue, int _x, int _y, int _w, int _h) :
	Sprite(renderer, pathToSurface, _x, _y, _w, _h)
{
	UpdateSwordSprite();
}

void Player::HandleInput(SDL_Event& e)
{
	//3 stages: keydown, keyup, and resolve
	//Keydown: set flag (lots of flags T_T)
	//Keydown: disable flag
	//Resolve: for any flags that are enabled, do a thing

	
	int positionX = this->GetXPosition();
	int RightInc = 3;
	int LeftInc = -3;
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.scancode) {
		case SDL_SCANCODE_W:
			std::cout << "high stance" << std::endl;
			this->AnimState = 0;
			this->UpdateSwordSprite();
			break;

		case SDL_SCANCODE_A:
			std::cout << "moving left" << std::endl;
			ResetAttack();
			this->SetXPosition(positionX + LeftInc);
			this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + LeftInc);
			break;

		case SDL_SCANCODE_S:
			std::cout << "low stance" << std::endl;
			this->AnimState = 1;
			this->UpdateSwordSprite();
			break;

		case SDL_SCANCODE_D:
			std::cout << "moving right" << std::endl;
			ResetAttack();
			this->SetXPosition(positionX + RightInc);
			this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + RightInc);
			break;

		case SDL_SCANCODE_F:
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
		case SDL_SCANCODE_LSHIFT:
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

		case SDL_SCANCODE_LSHIFT:
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

	/*
	int positionX = this->GetXPosition();
	int RightInc = 5;
	int LeftInc = -5;

	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.scancode) {
		case SDL_SCANCODE_A:
			MovingLeft = true;
			MovingRight = false;
			break;
		case SDL_SCANCODE_D:
			MovingLeft = false;
			MovingRight = true;
			break;
		case SDL_SCANCODE_W:
			HighStance = true;
			LowStance = false;
			break;
		case SDL_SCANCODE_S:
			HighStance = false;
			LowStance = true;
			break;
		case SDL_SCANCODE_F:
			Attacking = true;
			Blocking = false;
			break;
		case SDL_SCANCODE_LSHIFT:
			Attacking = false;
			Blocking = true;
			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		switch (e.key.keysym.scancode) {
		case SDL_SCANCODE_A:
			MovingLeft = false;
			break;
		case SDL_SCANCODE_D:
			MovingRight = false;
			break;
		case SDL_SCANCODE_W:
			HighStance = false;
			break;
		case SDL_SCANCODE_S:
			LowStance = false;
			break;
		case SDL_SCANCODE_F:
			Attacking = false;
			break;
		case SDL_SCANCODE_LSHIFT:
			Blocking = false;
			break;
		}
	}
	if (MovingRight) {
		this->SetXPosition(positionX + RightInc);
		this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + RightInc);
	}
	else if (MovingLeft) {
		this->SetXPosition(positionX + LeftInc);
		this->ActiveSwordSprite->SetXPosition(this->ActiveSwordSprite->GetXPosition() + LeftInc);
	}
	if (HighStance) {
		if (Attacking) {
			switch (GetAnimState()) {
			case 0:
				SetAnimState(4);
				break;
			case 4:
				SetAnimState(5);
				break;
			case 5:
				SetAnimState(6);
				break;
			case 6:
				SetAnimState(0);
				Attacking = false;
				break;
			}
		}
		else if (Blocking) {
			if (GetAnimState() != 2) {
				SetAnimState(2);
			}
		}
		else {
			SetAnimState(0);
		}
	}
	else if (LowStance) {
		if (Attacking) {
			switch (GetAnimState()) {
			case 1:
				SetAnimState(7);
				break;
			case 7:
				SetAnimState(8);
				break;
			case 8:
				SetAnimState(9);
				break;
			case 9:
				SetAnimState(1);
				Attacking = false;
				break;
			}
		}
		else if (Blocking) {
			if (GetAnimState() != 3) {
				SetAnimState(3);
			}
		}
		else {
			SetAnimState(1);
		}
	}
	UpdateSwordSprite();
	*/
}

void Player::SetHealth(float newHealth) {
	health = newHealth;
	if (health >= maxHealth) {
		health = maxHealth;
	}
	else if (health <= minHealth) {
		health = minHealth;
	}
}

void Player::ReduceHealth(float healthReduction) {

	health = health - healthReduction;
	if (health >= maxHealth) {
		health = maxHealth;
	}
	else if (health <= minHealth) {
		health = minHealth;
	}

}

float Player::GetHealth() {
	return health;
}

int Player::GetAnimState() {
	return AnimState;
}

void Player::SetAnimState(int _state)
{
	AnimState = _state;
}

Sprite* Player::GetSwordSprite()
{
	return ActiveSwordSprite;
}

bool Player::IsBlocking()
{
	return AnimState == 2 || AnimState == 3;
}

void Player::UpdateSwordSprite() {
	ActiveSwordSprite = new Sprite(
		renderer, SwordSpritePaths[AnimState],
		this->GetXPosition() + SwordSpriteOffsets[AnimState].GetX(),
		this->GetYPosition() + SwordSpriteOffsets[AnimState].GetY(),
		SwordSpriteHitboxes[AnimState].GetX(),
		SwordSpriteHitboxes[AnimState].GetY()
	);
}

void Player::ResetAttack() {
	if (AnimState == 6) {
		AnimState = 0;
	}
	else if (AnimState == 9) {
		AnimState = 1;
	}
	this->UpdateSwordSprite();
}




