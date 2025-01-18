#include "Rusher.h"

Rusher::Rusher(float x, float y, float scale, b2World* World, bool moveLeft) 
: Square(x, y, scale, World, new Texture("./Resources/rusher.bmp", 6, 4)){
	this->time = 0;
	this->tag = 3;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	this->moveLeft = moveLeft;
}

void Rusher::Collide(Square *other){
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