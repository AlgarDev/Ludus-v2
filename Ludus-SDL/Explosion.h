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

class Explosion : public Square
{
public:
	~Explosion();
    float lastSpriteUpdateTimestamp;
	float time;
    bool animationFinished;
    void upgrade();
	Explosion(float x, float y, float scale, b2World *World, Texture* texture);
	void update(float deltaTime);
	bool isActive();
};