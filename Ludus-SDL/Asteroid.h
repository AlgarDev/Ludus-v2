#pragma once
#include "Texture.h"
#include "Square.h"
#include <string>

class Asteroid : public Square
{
public:
	void Collide(Square* other) override;
	Asteroid(float x, float y, float scale, b2World* World, bool isMetal, int tier, float dx, float dy);
	void update(float deltaTime);
	void move();

private:
	float time;
	float lastSpriteUpdateTimestamp;
    int tier;
    bool isMetal;
    float dx, dy;

};
