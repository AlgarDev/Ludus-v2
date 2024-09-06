#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <box2d/box2d.h>
#include <iostream>
class Square
{
public:
	void render();
	void move(float dx, float dy, float rotation);
	Square(int x, int y, int width, int height);

private:
	b2BodyDef bdef;
	b2PolygonShape* pshape;
	b2FixtureDef fdef;

};

