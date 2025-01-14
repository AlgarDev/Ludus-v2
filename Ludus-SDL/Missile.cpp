#include "Missile.h"


Missile::Missile(int missileTier, float x, float y, float scale, b2World* World, Texture* texture) 
: Square(x, y, scale, World, texture){
	this->time = 0;
    this->lastSpriteUpdateTimestamp = 0;
    this->missileTier = missileTier;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = missileTier;
}

void Missile::update(Renderer *renderer, float deltaTime) {
	time += deltaTime;
	move(0, -3);
	if(this->time - this->lastSpriteUpdateTimestamp >= 0.1f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->cycleRigth();
	}
}

void Missile::move(float dx, float dy) {
	b2Vec2 force(dx,dy);
	//apply immediate force upwards

	Body->SetLinearVelocity(force);
}
