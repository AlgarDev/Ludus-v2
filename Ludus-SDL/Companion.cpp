#include "Companion.h"

Companion::Companion(float x, float y, float scale, b2World* World)
    : Square(x, y, scale, World, new Texture("./Resources/clone.bmp", 5, 4)), time(0), lastShootTimestamp(0), lastSpriteUpdateTimestamp(0), hp(3), lastHitTimeStamp(0), missileTier(0)
{
    tag = 10;
}

void Companion::Collide(Square* other)
{
	if(( other->tag == 3 || other->tag == 4 ) && time - lastHitTimeStamp > 0.2f){
		hp--;
		printf("hp == %d\n", hp);
		lastHitTimeStamp = time;
	}else if( other->tag == 7) missileTier = missileTier == 2 ? missileTier : missileTier+1;
	else if( other->tag == 8) hp += 3;
}

void Companion::update(float deltaTime)
{
    // Update the companion's state based on deltaTime
    time += deltaTime;

    // Update sprite animation timing (if applicable)
    if(this->time - this->lastSpriteUpdateTimestamp >= 0.05f){
	    this->lastSpriteUpdateTimestamp = this->time;
	    this->texture->fulllCycle();
        if(this->texture->spriteRow == 5) this->texture->spriteRow = 0;
    }
}

void Companion::move(float dx, float dy)
{
    b2Vec2 force(dx,dy);
	Body->SetLinearVelocity(force);
}

void Companion::setPosition(float x, float y){
	b2Vec2 newPosition(x, y);
	Body->SetTransform(newPosition, Body->GetAngle());
}

bool Companion::isDead()
{
    return hp <= 0;
}

bool Companion::canShoot(){
	if(this->time - this->lastShootTimestamp >= this->shootDelay){
        lastShootTimestamp = time;
        return true;
    }
    return false;
}
