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
	virtual void Collide(Square* other){
		std::cout << "Base Square collided with another Square." << std::endl;
	}
	Square(float x, float y, float scale, b2World *World, Texture* texture);
	void removeCollisions();

protected:
	float getX();
	float getY();
	float width;
	float height;
	float scale;
	b2BodyDef bdef;
	b2PolygonShape* pshape;
	b2FixtureDef fdef;
	b2Body* Body;
	Texture* texture;
	b2World* World;
};
