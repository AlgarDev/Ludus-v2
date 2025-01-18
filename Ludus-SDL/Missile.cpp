#include "Missile.h"


Missile::Missile(int missileTier, float x, float y, float scale, b2World* World, bool isPlayer) 
: Square(x, y, scale, World, isPlayer ? new Texture("./Resources/missile.bmp", 3, 2) : new Texture("./Resources/EnWeap6.bmp", 1, 8)){
	this->time = 0;
    this->lastSpriteUpdateTimestamp = 0;
    this->missileTier = missileTier;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = missileTier;
	this->tag = isPlayer ? 2 : 4;
	this->isPlayer = isPlayer;
	didHit = false;
}

void Missile::update(float deltaTime) {
	time += deltaTime;
	move(0, isPlayer ? -5 : 4);
	if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->cycleRigth();
	}
}

void Missile::Collide(Square *other){
	if(isPlayer && other->tag == 3)	didHit = true;
	else if ( !isPlayer && other->tag == 1) didHit= true;
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
