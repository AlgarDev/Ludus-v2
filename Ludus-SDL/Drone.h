#pragma once
#include "Texture.h"
#include "Square.h"
#include <list>

class Drone : public Square
{
public:
	void Collide(Square* other) override;
	float time;
	float lastSpriteUpdateTimestamp;
	Drone(float x, float y, float scale, b2World* World);
	void update(float deltaTime);
	void move();

};
