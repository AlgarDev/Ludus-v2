#include "Player.h"

Player::Player(float x, float y, float scale, b2World* World) 
: Square(x, y, scale, World, new Texture("./Resources/Ship1.bmp", 1, 7)){
	this->time = 0;
	this->willShoot = false;
	this->dx = 0;
	this->dy = 0;
	validX = x;
	validY = y;
	this->tag = 1;
	this->lastShootTimestamp = 0;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 3; //Default Player
	this->texture->spriteRow = 0; //Default Player
	lastHitTimeStamp = 0;
	hp = 15;
}
/*
TAGS
1 - Player
2 - Player Missile tier 1
3 - Enemy
4 - Enemy Missile
*/
void Player::Collide(Square* other) {
	if(( other->tag == 3 || other->tag == 4 ) && time - lastHitTimeStamp > 0.2f){
		hp--;
		printf("hp == %d\n", hp);
		lastHitTimeStamp = time;
	}
}
void Player::move(float dx, float dy) {
    b2Vec2 force(dx,dy);
    Body->SetLinearVelocity(force);
}

void Player::setPosition(float x, float y){
    b2Vec2 newPosition(x, y);
    Body->SetTransform(newPosition, Body->GetAngle());
}

bool Player::isValidX(){
	return getX() > 0.0f && 10.0f > getX();
}

bool Player::isValidY(){
	return getY() > 0.0f && 10.0f > getY();
}

bool Player::isPositionValid(){
	return isValidX() && isValidY();
}

void Player::update(float deltaTime) {
	for ( Missile* missile : missiles) {
        missile->update(deltaTime);
		if(missile->isExploding()){
			Explosion *temp = new Explosion( missile->getX(), missile->getY(), 0.01f, this->World, new Texture("./Resources/explode16.bmp", 2, 5));
			temp->removeCollisions();
			this->explosions.push_back( temp );
		}
    }
	for ( Explosion* explosion : explosions) {
        explosion->update(deltaTime);
    }
	explosions.remove_if([](Explosion* explosion) {
		if(!explosion->isActive()){
			delete explosion;
			return true;
		}
		return false;
	});
	missiles.remove_if([](Missile* missile) {
		if(!missile->isActive()){
			delete missile;
			return true;
		}
		return false;
	});
	move(this->dx, this->dy);
	if(isValidY()){
		validY = getY();
	}else{
		setPosition(getX(), validY);
	}
	if(isValidX()){
		validX = getX();
	}else{
		setPosition(validX, getY());
	}
	time += deltaTime;
	if(willShoot && canShoot()){
		shoot();
	}
	if(this->dx > 0 
	&& this->texture->spriteColumn +1 < this->texture->numberOfColumns 
	&& this->time - this->lastSpriteUpdateTimestamp >= 0.1f){
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
	shoot(getX(), getY());
}

void Player::shoot(float x,float y){
	this->lastShootTimestamp = this->time;
	Missile *temp = new Missile( x, y, 0.01f, World, true);
	missiles.push_back( temp );
}

bool Player::canShoot(){
	return this->time - this->lastShootTimestamp >= this->shootDelay;
}

int Player::getHp(){
	return hp;
}

void Player::renderWithDependent(){
	render();
	for ( Missile* missile : missiles) {
        missile->render();
    }
	for ( Explosion* explosion : explosions) {
        explosion->render();
    }
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

bool Player::isDead(){
	return 0 >= hp; 
}

void Player::useKeyboardState(const Uint8* keyboardState){
	if(keyboardState[SDL_SCANCODE_W]){
		this->dy = -3;
	}
	if(keyboardState[SDL_SCANCODE_A]){
		this->dx = -3;
	}
	if(keyboardState[SDL_SCANCODE_S]){
		this->dy = 3;	
	}
	if(keyboardState[SDL_SCANCODE_D]){
		this->dx = 3;
	}
	if(keyboardState[SDL_SCANCODE_SPACE]){
		this->willShoot = true;	
	}
}