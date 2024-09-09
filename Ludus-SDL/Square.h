#pragma once
#include "Square.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"
class Square
{
public:
	char type;
	void render();
	std::function<void(Square*)> movement_fun;
	void setMovementFun(std::function<void(Square*)> movement_fun);
	Square(float x, float y, float width, float height, b2World *World, Texture* texture);
	void move(float dx, float dy, float rotation, char movementType);

private:
	Texture* texture;
	float width;
	float height;
	b2BodyDef bdef;
	b2PolygonShape* pshape;
	b2FixtureDef fdef;
	b2Body* Body;

};
