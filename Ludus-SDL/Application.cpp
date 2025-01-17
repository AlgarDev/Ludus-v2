#include "Engine.h"
#include "ContactListener.h"
#include "Event.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;

IntAndPointer getRandomSpawn(){
	// Create a random device and generator
    std::random_device rd;  // Seed
    std::mt19937 gen(rd()); // Mersenne Twister random number generator

    // Define a uniform integer distribution between 0 and 100
    std::uniform_int_distribution<> dist(0, 100);

	IntAndPointer result;
	result.number = dist(gen);
	result.pointer = (void*)nullptr;
	return result;
}
/*
void testDefineMovement(Player* entity, Engine* Engine, float deltaTime) {
	entity->time += deltaTime;
	const float amplitude = 3.0f; // Maximum force applied
	const float frequency = 1.f; // Frequency of oscillation in Hz
	// Calculate the sinusoidal force
	float force = amplitude * sin(frequency * entity->time);
	entity->move(force, 0.0f, 0.0f, 'i');
}
*/
int main() {
	
	b2World *World = new b2World(b2Vec2(0, 0));	// Physics Engine
	ContactListener* listener = new ContactListener();
    World->SetContactListener(listener);

	Engine *eng = new Engine(WinWidth, WinHeight);
	Texture *explosionTexture = new Texture("./Resources/explode64.bmp", 2, 5);
	Player *player = new Player(3.f, 3.f, 0.0125f, World, explosionTexture);

	Event *spawnRandomMobsEvent = new Event(1, 5);
	
	Texture* texture = new Texture("./Resources/Galaxy2.bmp", 1, 1);
	Square *background = new Square(5, 5, 0.025f, World, texture);
	background->removeCollisions();
	
	Scene *sc = new Scene(player, World);	//Game Logic
	
	sc->addEvent(spawnRandomMobsEvent);

	sc->addBackground(background);
	
	eng->init(World, sc);
	
	eng->run();

	return 0;
}