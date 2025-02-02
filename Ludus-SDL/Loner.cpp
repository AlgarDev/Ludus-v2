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
	hp = 5;
}


bool Loner::isActive(){
	return !isDead() &&  15.0f > getY();
}
bool Loner::isDead(){
	return 0 >= hp;
}

void Loner::Collide(Square *other){
	if(other->tag == 2) hp--;
	else if(other->tag == 5) hp -= 2;
	else if(other->tag == 6) hp -= 4;
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
			Explosion *temp = new Explosion( missile->getX(), missile->getY(), 0.01f, this->World, new Texture("./Resources/explode16.bmp", 2, 5));
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
	Missile *temp = new Missile( getX(), getY(), 0.015f, World, false);
	missiles.push_back( temp );
}