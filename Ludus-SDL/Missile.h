#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"
#include "Square.h"

#ifndef  HEADER_RENDERER
class Renderer;
#endif

class Missile : public Square
{
public:

	int missileTier;
    int lastSpriteUpdateTimestamp;
	float time;
	float hitX, hitY;
	bool isExploding;
    void upgrade();
	void update(Renderer* renderer);
	Missile(int missileTier, float x, float y, float scale, b2World *World, Texture* texture);
	void update(Renderer* renderer, float deltaTime);
	void move(float dx, float dy);
};