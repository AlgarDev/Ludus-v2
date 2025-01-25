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
#include "Engine.h"
#include "Explosion.h"
#include "Companion.h"
#include <algorithm>

class Player : public Square
{
public:
	std::list<Missile*> missiles;
	std::list<Explosion*> explosions;
	void Collide(Square* other) override;
	Texture *missileTextures;
	Texture *explosionTexture;
	char type;
	float time;
	float dx, dy;
	float shootDelay = 0.5f;
	bool willShoot;
	float lastShootTimestamp;
	float lastSpriteUpdateTimestamp;
	Player(float x, float y, float scale, b2World *World);
	void update(float deltaTime);
	void move(float dx, float dy);
	/* void setMovement(std::function<void(Player*,Engine*,float)> movement); */
	void setAction(SDL_Keycode Key, bool KeyDown);
	void useKeyboardState(const Uint8* keyboardState);
	void renderWithDependent();
	bool isDead();
	int getHp();

private:
	float validX, validY;
	bool isPositionValid();
	Companion *left;
	Companion *rigth;
	bool leftToCreate, rigthToCreate;
	bool hasLeftCompanion, hasRigthCompanion;
	bool isValidX();
	bool isValidY();
	bool canShoot();
	void shoot();
	void shoot(float x, float y, int tier);
	void setPosition(float x, float y);
	int hp;
	int missileTier;
	float lastHitTimeStamp;
	/* std::function<void(Player*,Engine*,float)> movement; */

};
