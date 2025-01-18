#include "Asteroid.h"

Asteroid::Asteroid(float x, float y, float scale, b2World* World, bool isMetal, int tier, float dx, float dy)
: Square(x, y, scale, World, new Texture( std::string("./Resources/") + (isMetal ? std::string("MA") : std::string("SA")) + std::string("ster") + (tier == 1 ? std::string("32") : tier == 2 ? std::string("64") : ("96")) + std::string(".bmp"),
tier == 1 ? 2 : tier == 2 ? 3 :5, tier == 1 ? 8 : tier == 2 ? 8 :5)){
	this->time = 0;
	this->tag = 3;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	this->isMetal = isMetal;
	this->tier = tier;
	this->dx = dx;
	this->dy = dy;
}

void Asteroid::Collide(Square *other){
}

	void Asteroid::update(float deltaTime){
        time += deltaTime;
        move();
		if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
		    this->lastSpriteUpdateTimestamp = this->time;
		    this->texture->fulllCycle();
	    }
	}

	void Asteroid::move(){
        b2Vec2 force( dx, dy);
	    Body->SetLinearVelocity(force);
    }