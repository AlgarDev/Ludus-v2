#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include <list>
#include "Texture.h"
#include "Square.h"
#include "Missile.h"
#include "Renderer.h"

class Player : public Square
{
public:
	std::list<Missile*> missiles;
	Texture *missileTextures;
	char type;
	float time;
	float dx, dy;
	float shootDelay = 0.5f;
	bool willShoot;
	float lastShootTimestamp;
	float lastSpriteUpdateTimestamp;
	void update(Renderer* renderer);
	Player(float x, float y, float scale, b2World *World, Texture* texture);
	void update(Renderer* renderer, float deltaTime);
	void move(float dx, float dy);
	/* void setMovement(std::function<void(Player*,Renderer*,float)> movement); */
	void setAction(SDL_Keycode Key, bool KeyDown);
	void useKeyboardState(const Uint8* keyboardState);

private:
	bool canShoot();
	void shoot(Renderer *renderer);
	/* std::function<void(Player*,Renderer*,float)> movement; */

};
