#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"
#include "Square.h"

#ifndef  HEADER_Engine
class Engine;
#endif

class Missile : public Square
{
public:
	void Collide(Square* other) override;
	~Missile();
	int missileTier;
    float lastSpriteUpdateTimestamp;
	float time;
	float hitX, hitY;
	bool didHit, isPlayer;
    void upgrade();
	Missile(int missileTier, float x, float y, float scale, b2World *World, bool isPlayer);
	void update(float deltaTime);
	void move(float dx, float dy);
	bool isActive();
	bool isExploding();
};