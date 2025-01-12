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

class Player : public Square
{
public:

	char type;
	float time;
	float dx, dy;
	bool willShoot;
	float lastShootTimestamp;
	void update(Renderer* renderer);
	Player(float x, float y, float scale, b2World *World, Texture* texture);
	void update(Renderer* renderer, float deltaTime);
	void move(float dx, float dy);
	/* void setMovement(std::function<void(Player*,Renderer*,float)> movement); */
	void setAction(SDL_Keycode Key, bool KeyDown);
	void useKeyboardState(const Uint8* keyboardState);

private:
	/* std::function<void(Player*,Renderer*,float)> movement; */

};
