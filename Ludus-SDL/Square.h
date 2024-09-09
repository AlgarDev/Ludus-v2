#pragma once
#include "Square.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"

#ifndef  HEADER_RENDERER
class Renderer;
#endif

class Square
{
public:
	char type;
	float time;
	void render();
	void update(Renderer* renderer);
	Square(float x, float y, float width, float height, b2World *World, Texture* texture);
	void update(Renderer* renderer, float deltaTime);
	void move(float dx, float dy, float rotation, char movementType);
	void setMovement(std::function<void(Square*,Renderer*,float)> movement);

private:
	std::function<void(Square*,Renderer*,float)> movement;
	Texture* texture;
	float width;
	float height;
	b2BodyDef bdef;
	b2PolygonShape* pshape;
	b2FixtureDef fdef;
	b2Body* Body;

};
