#pragma once
#include "Texture.h"
#include "Square.h"
#include <list>

class Upgrade : public Square
{
public:
	void Collide(Square* other) override;
	float time;
	float lastSpriteUpdateTimestamp;
	Upgrade(float x, float y, float scale, b2World* World, int upgradeTag);
	void update(float deltaTime);
	void move();
	bool isActive();

private:
    bool isActiveUpgrade;

};
