#pragma once
#include "Texture.h"
#include "Square.h"
#include <list>

class Rusher : public Square
{
public:
	void Collide(Square* other) override;
	float time;
	float lastSpriteUpdateTimestamp;
	Rusher(float x, float y, float scale, b2World* World, bool moveLeft);
	void update(float deltaTime);
	void move();

private:
    bool moveLeft;
	bool canShoot();
	void shoot();

};
