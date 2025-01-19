#include "Drone.h"

Drone::Drone(float x, float y, float scale, b2World* World) 
: Square(x, y, scale, World, new Texture("./Resources/drone.bmp", 2, 8)){
	this->time = 0;
	this->tag = 3;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	hp = 3;
}

void Drone::Collide(Square *other){
	if(other->tag == 2) hp--;
}

	void Drone::update(float deltaTime){
        time += deltaTime;
        move();
		if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
		    this->lastSpriteUpdateTimestamp = this->time;
		    this->texture->fulllCycle();
	    }
	}

	void Drone::move(){
	    const float amplitude = 3.2f; // Maximum force applied
	    const float frequency = 4.f; // Frequency of oscillation in Hz
	    // Calculate the sinusoidal force
	    float dx = amplitude * sin(frequency * time);
        b2Vec2 force( dx, 2.0f);

	    Body->SetLinearVelocity(force);
    }

bool Drone::isActive(){
	return !isDead() && 15.0f > getY() ;
}
bool Drone::isDead(){
	return hp <= 0;
}