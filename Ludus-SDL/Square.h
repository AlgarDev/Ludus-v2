#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"

class Square
{
public:
	void render();
	Square(float x, float y, float width, float height, b2World *World, Texture* texture);

protected:
	float width;
	float height;
	b2BodyDef bdef;
	b2PolygonShape* pshape;
	b2FixtureDef fdef;
	b2Body* Body;
	Texture* texture;
};
