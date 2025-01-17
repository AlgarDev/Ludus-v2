#include "Loner.h"

Loner::Loner(float x, float y, float scale, b2World* World) 
: Square(x, y, scale, World, new Texture("./Resources/LonerA.bmp", 4, 4)){
	this->time = 0;
	this->tag = 3;
	this->lastShootTimestamp = 0;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	this->missileTextures = new Texture("./Resources/EnWeap6.bmp", 1, 8);
	this->explosionTexture = new Texture("./Resources/explode64.bmp", 2, 5);
}

void Loner::Collide(Square *other){
    printf("LONER HIT\n");
}

	void Loner::update(float deltaTime){
        time += deltaTime;
        move();
    }

	void Loner::move(){
	    const float amplitude = 3.2f; // Maximum force applied
	    const float frequency = 4.f; // Frequency of oscillation in Hz
	    // Calculate the sinusoidal force
	    float dx = amplitude * sin(frequency * time);
        b2Vec2 force( dx, 1);

	    Body->SetLinearVelocity(force);
    }
	void Loner::renderWithDependent(){
        render();
    }
	bool Loner::canShoot(){
        return false;
    }
	void Loner::shoot(){
        
    }