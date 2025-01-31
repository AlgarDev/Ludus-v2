#pragma once
#include "Texture.h"
#include "Square.h"

class Companion : public Square
{
public:
	void Collide(Square* other) override;
	float time;
	float shootDelay = 0.65f;
	float lastShootTimestamp;
	float lastSpriteUpdateTimestamp;
    float lastHitTimeStamp;
    int missileTier;
	Companion(float x, float y, float scale, b2World* World);
	void update(float deltaTime);
	void move(float dx, float dy);
	bool isDead();
    bool canShoot();
    void setPosition(float x, float y);
	bool isValidX();
	bool isValidY();
	bool isPositionValid();
private:
    int hp;
};
