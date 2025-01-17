#include "Explosion.h"


Explosion::Explosion(float x, float y, float scale, b2World* World, Texture* texture) 
: Square(x, y, scale, World, texture){
	this->time = 0;
    this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	this->tag = 2;
	animationFinished = false;
}

void Explosion::update(float deltaTime) {
	time += deltaTime;
	if(this->time - this->lastSpriteUpdateTimestamp >= 0.1f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->fulllCycle();
        if(this->texture->spriteColumn == 0 && this->texture->spriteRow == 0) animationFinished = true;
		
	}
}


bool Explosion::isActive(){
	return !animationFinished;
}

Explosion::~Explosion(){
}
