#pragma once
#include "Texture.h"
#include "Square.h"
#include "Explosion.h"
#include <list>

class Loner : public Square
{
public:
	std::list<Explosion*> explosions;
	void Collide(Square* other) override;
	Texture *missileTextures;
	Texture *explosionTexture;
	float time;
	float shootDelay = 0.5f;
	float lastShootTimestamp;
	float lastSpriteUpdateTimestamp;
	Loner(float x, float y, float scale, b2World* World);
	void update(float deltaTime);
	void move();
	void renderWithDependent();

private:
	bool canShoot();
	void shoot();

};
