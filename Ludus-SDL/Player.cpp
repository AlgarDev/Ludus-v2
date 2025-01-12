#include "Player.h"

Player::Player(float x, float y, float scale, b2World* World, Texture* texture) 
: Square(x, y, scale, World, texture){
	this->time = 0;
	this->willShoot = false;
	this->lastShootTimestamp = 0;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 3; //Default Player
	this->texture->spriteRow = 0; //Default Player
}

void Player::move(float dx, float dy) {
	b2Vec2 force(dx,dy);
	//apply immediate force upwards

	Body->SetLinearVelocity(force);
}

void Player::update(Renderer *renderer, float deltaTime) {
	time += deltaTime;
	move(this->dx, this->dy);
	if(willShoot && canShoot()){
		shoot();
	}
	if(this->dx > 0 
	&& this->texture->spriteColumn +1 < this->texture->numberOfColumns 
	&& this->time - this->lastSpriteUpdateTimestamp >= 0.1f){
		std::cout << this->texture->spriteColumn << std::endl;
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->cycleRigth();
	} else if(0 > this->dx
	&& this->texture->spriteColumn > 0 
	&& this->time - this->lastSpriteUpdateTimestamp >= 0.1f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->cycleLeft();
	}else if( 0 == this->dx) this->texture->moveSprite(0, 3);
}

void Player::shoot(){
	this->lastShootTimestamp = this->time;
	std::cout << "SHOOTING" << std::endl;
}

bool Player::canShoot(){
	return this->time - this->lastShootTimestamp >= this->shootDelay;
}



void Player::setAction(SDL_Keycode Key, bool KeyDown){
	switch (Key) {
		case SDLK_w:  // 'W' key pressed
			this->dy = -3 * KeyDown;
			// Handle W key press
			break;
		case SDLK_a:  // 'A' key pressed
			if(this->dx > 0){
				this->texture->moveSprite(0, 3);
			}
			this->dx = -3 * KeyDown;
			break;
		case SDLK_s:  // 'S' key pressed
			this->dy = 3 * KeyDown;
			// Handle S key press
			break;
		case SDLK_d:  // 'D' key pressed
			if(0 > this->dx){
				this->texture->moveSprite(0, 3);
			}
			this->dx = 3 * KeyDown;
			break;
		case SDLK_SPACE:
			this->willShoot = KeyDown;
			// Handle shoot
			break;
		}
}

void Player::useKeyboardState(const Uint8* keyboardState){
	if(keyboardState[SDL_SCANCODE_W]){
		this->dy = -3;
	}
	if(keyboardState[SDL_SCANCODE_A]){
		this->dx = -3;
		//std::cout << "HOLDING left" << std::endl;
	}
	if(keyboardState[SDL_SCANCODE_S]){
		this->dy = 3;
		
	}
	if(keyboardState[SDL_SCANCODE_D]){
		this->dx = 3;
		//std::cout << "HOLDING rigth" << std::endl;
	}
	if(keyboardState[SDL_SCANCODE_SPACE]){
		this->willShoot = true;	
	}
}

/*
void Player::setMovement(std::function<void(Player*,Renderer*,float)> movement) {
	this->movement = movement;
}
*/