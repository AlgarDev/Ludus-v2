#pragma once
#include "Square.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>

Square::Square(float x, float y, float width, float height, b2World* World) {
	bdef.type = b2_dynamicBody;
	bdef.position.Set(x, y);
	Body = World->CreateBody(&bdef);
	pshape = new b2PolygonShape();
	pshape->SetAsBox(width, height);

	fdef.shape = pshape;
	fdef.density = 1;
	Body->CreateFixture(&fdef);
	this->width = width;
	this->height = height;
}

void Square::render() {


	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	
	float x = Body->GetPosition().x;
	float y = Body->GetPosition().y;
	printf("%f %f\n", x, y);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x , y + height);
	glEnd();
}

void Square::move(float dx, float dy, float rotation, char movementType) {
	switch (movementType)
	{
	case 'f':
		//apply gradual force upwards
		Body->ApplyForce(b2Vec2(0, 50), Body->GetWorldCenter(), true);
		break;
	case 'i':
		//apply immediate force upwards
		Body->ApplyLinearImpulse(b2Vec2(0, 50), Body->GetWorldCenter(), true);
		break;
	case 't':
		//teleport or 'warp' to new location
		Body->SetTransform(b2Vec2(10, 20), 0);
		break;
	default:
		return;
	}
}

void Square::setMovementFun(std::function<void(Square*)> movement_fun) {
	this->movement_fun = movement_fun;
}