#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <list>
#include <chrono>
#include "Player.h"
#include "Event.h"
#include "Loner.h"
#include "Rusher.h"
#include "Drone.h"
#include "Asteroid.h"
#include "Explosion.h"
#include "Upgrade.h"
#include "Hud.h"

class Player;

class Scene
{
    public:
    void addHud(Hud* hud);
    Scene(Player *player, b2World *World);
    void addBackground(Square *background);
    void renderScene();
    void updateScene(float deltaTime);
    void keyboardEvent(SDL_Keycode Key, bool KeyDown);
    void keyboardState(const Uint8* currentKeyStates);
    void addEvent(Event * event);
    void handleEvent(IntAndPointer eventResult);
    void setNumberHud(Hud *score);
    private:
    Hud* score;
    Hud* hp;
	std::list<Event*> events;
	std::list<Hud*> huds;
	std::list<Loner*> loners;
	std::list<Rusher*> rushers;
	std::list<Drone*> drones;
	std::list<Asteroid*> asteroids;
	std::list<Explosion*> explosions;
	std::list<Upgrade*> upgrades;
    Player *player;
    Square *background;
    b2World *World;
    private:
    void clearData();
};