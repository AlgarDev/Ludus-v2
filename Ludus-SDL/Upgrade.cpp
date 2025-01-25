#include "Upgrade.h"

Upgrade::Upgrade(float x, float y, float scale, b2World* World, int upgradeTag) 
: Square(x, y, scale, World, upgradeTag == 1 ? new Texture("./Resources/PUWeapon.bmp", 2, 4) : upgradeTag == 2 ? new Texture("./Resources/PUShield.bmp", 2, 4) : new Texture("./Resources/clone.bmp", 5, 4) ){
	this->time = 0;
	this->tag = 6+upgradeTag;
	this->lastSpriteUpdateTimestamp = 0;
	this->texture->spriteColumn = 0;
	this->texture->spriteRow = 0;
	isActiveUpgrade = true;
}

/*
TAGS
1 - Player
2 - Player Missile tier 1
3 - Enemy
4 - Enemy Missile
5 - Player Missile tier 2
6 - Player Missile tier 3
7 - Missile Upgrade
8 - HP upgrade
9 - Companion Upgrade
10 - Companion
*/

void Upgrade::Collide(Square *other){
	if(other->tag == 1 || (other->tag == 10 && tag != 9) ) isActiveUpgrade = false;
}

void Upgrade::update(float deltaTime){
    time += deltaTime;
    move();
	if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
	    this->lastSpriteUpdateTimestamp = this->time;
	    this->texture->fulllCycle();
        if(this->texture->spriteRow == 5) this->texture->spriteRow = 0;
    }
}

void Upgrade::move(){
    b2Vec2 force( 0.0f, 2.25f);
    Body->SetLinearVelocity(force);
}

bool Upgrade::isActive(){
	return isActiveUpgrade;
}