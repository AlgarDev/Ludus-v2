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
class Player;

class Scene
{
    public:
    Scene(Player *player, b2World *World);
    void addBackground(Square *background);
    void renderScene();
    void updateScene(float deltaTime);
    void keyboardEvent(SDL_Keycode Key, bool KeyDown);
    void keyboardState(const Uint8* currentKeyStates);
    void addEvent(Event * event);
    void handleEvent(IntAndPointer eventResult);
    private:
	std::list<Event*> events;
	std::list<Loner*> loners;
	std::list<Rusher*> rushers;
	std::list<Drone*> drones;
    Player *player;
    Square *background;
    b2World *World;
};