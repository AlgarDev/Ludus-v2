#include "Loner.h"

Loner::Loner(float x, float y, float scale, b2World* World) 
: Square(x, y, scale, World, getRandomTexture()){
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
}

	void Loner::update(float deltaTime){
        time += deltaTime;
        move();
		if(this->time - this->lastShootTimestamp >= 2.0f){
			shoot();
		}
		for ( Missile* missile : missiles) {
        missile->update(deltaTime);
		if(missile->isExploding()){
			Explosion *temp = new Explosion( missile->getX(), missile->getY(), 0.005f, this->World, new Texture("./Resources/explode64.bmp", 2, 5));
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

		if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
		this->lastSpriteUpdateTimestamp = this->time;
		this->texture->fulllCycle();
	}
	}

	void Loner::move(){
	    /*const float amplitude = 3.2f; // Maximum force applied
	    const float frequency = 4.f; // Frequency of oscillation in Hz
	    // Calculate the sinusoidal force
	    float dx = amplitude * sin(frequency * time);*/
        b2Vec2 force( 0.0f, 1.0f);

	    Body->SetLinearVelocity(force);
    }
	void Loner::renderWithDependent(){
        render();
		for ( Missile* missile : missiles) {
        missile->render();
    }
	for ( Explosion* explosion : explosions) {
        explosion->render();
    }
    }
	bool Loner::canShoot(){
        return false;
    }
	void Loner::shoot(){
	this->lastShootTimestamp = this->time;
	Missile *temp = new Missile( 0, getX(), getY(), 0.015f, World, false);
	missiles.push_back( temp );
}