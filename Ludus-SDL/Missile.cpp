#include "Missile.h"


Missile::Missile(int missileTier, float x, float y, float scale, b2World* World, Texture* texture) 
: Square(x, y, scale, World, texture){
	this->time = 0;
    this->lastSpriteUpdateTimestamp = 0;
    this->missileTier = missileTier;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = missileTier;
	this->tag = 2;
	didHit = false;
}

void Missile::update(float deltaTime) {
	time += deltaTime;
	move(0, -5);
	if(this->time - this->lastSpriteUpdateTimestamp >= 0.2f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->cycleRigth();
	}
}

void Missile::Collide(Square *other){
	if(other->tag != 1 && other->tag != 2)	didHit = true;
	printf("Missile Hit\n");
}

void Missile::move(float dx, float dy) {
	b2Vec2 force(dx,dy);
	Body->SetLinearVelocity(force);
}

bool Missile::isActive(){
	return getY() > 0.0f && !didHit;
}

bool Missile::isExploding(){
	return didHit;
}

Missile::~Missile(){
}
