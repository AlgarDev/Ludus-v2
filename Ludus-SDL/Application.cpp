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

	RandomSpawnEvent *spawnRandomMobsEvent = new RandomSpawnEvent(0.0f, 1.0f, World);
	
	Texture* texture = new Texture("./Resources/Galaxy2.bmp", 1, 1);
	Square *background = new Square(5, 5, 0.015f, World, texture);
	background->removeCollisions();
	
	Scene *sc = new Scene(player, World);	//Game Logic
	
	sc->addEvent(spawnRandomMobsEvent);
    Texture *texture16x16 =new Texture("./Resources/font16x16.bmp", 12, 8);
    Texture *texture8x8 =new Texture("./Resources/font8x8.bmp", 16, 8);
    sc->setNumberHud(new Hud(3.0f, 0.5f, 0.3f, 0.3f, texture16x16, 0, 10));
    sc->addHud(new Hud(0.2f, 0.2f, 0.16f, 0.16f, texture8x8, "Player One"));
    //sc->addHud(new Hud(3.0f, 0.9f, 0.16f, 0.16f, texture8x8, "Hi Score"));
    //sc->addHud(new Hud(3.0f, 0.18f, 0.16f, 0.16f, texture8x8, 0));

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
5 - Player Missile tier 2
6 - Player Missile tier 3
7 - Missile Upgrade
8 - HP upgrade
9 - Companion Upgrade
10 - Companion


                "${workspaceFolder}\\Ludus-SDL\\Application.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Asteroid.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Upgrade.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Drone.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Engine.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Event.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Explosion.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Loner.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Missile.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Player.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\RandomSpawnEvent.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Scene.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Rusher.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Square.cpp", //All Sources
                "${workspaceFolder}\\Ludus-SDL\\Texture.cpp", //All Sources
*/