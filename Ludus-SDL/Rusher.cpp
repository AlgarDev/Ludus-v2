#include "Rusher.h"

Rusher::Rusher(float x, float y, float scale, b2World* World, bool moveLeft) 
: Square(x, y, scale, World, new Texture("./Resources/rusher.bmp", 6, 4)){
	this->time = 0;
	this->tag = 3;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	this->moveLeft = moveLeft;
	hp = 3;
}

void Rusher::Collide(Square *other){
	if(other->tag == 2) hp--;
	else if(other->tag == 5) hp -= 2;
	else if(other->tag == 6) hp -=4;
}

	void Rusher::update(float deltaTime){
        time += deltaTime;
        move();
		if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
		    this->lastSpriteUpdateTimestamp = this->time;
		    this->texture->fulllCycle();
	    }
	}

void Rusher::move(){
    b2Vec2 force( moveLeft ? -2.25f : 2.25f, 0.0f);
    Body->SetLinearVelocity(force);
}

bool Rusher::isActive(){
	return !isDead() && 15.0f > getY() ;
}
bool Rusher::isDead(){
	return hp <= 0;
}