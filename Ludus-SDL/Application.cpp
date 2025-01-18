#include "Engine.h"
#include "ContactListener.h"
#include "RandomSpawnEvent.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;

int main() {
	
	b2World *World = new b2World(b2Vec2(0, 0));	// Physics Engine
	ContactListener* listener = new ContactListener();	
    World->SetContactListener(listener);

	Engine *eng = new Engine(WinWidth, WinHeight);
	Player *player = new Player(3.f, 3.f, 0.005f, World);

	RandomSpawnEvent *spawnRandomMobsEvent = new RandomSpawnEvent(1, 5, World);
	
	Texture* texture = new Texture("./Resources/Galaxy2.bmp", 1, 1);
	Square *background = new Square(5, 5, 0.015f, World, texture);
	background->removeCollisions();
	
	Scene *sc = new Scene(player, World);	//Game Logic
	
	sc->addEvent(spawnRandomMobsEvent);

	sc->addBackground(background);
	
	eng->init(World, sc);
	
	eng->run();

	return 0;
}

/*
TAGS
1 - Player
2 - Player Missile tier 1
3 - Enemy
4 - Enemy Missile
*/