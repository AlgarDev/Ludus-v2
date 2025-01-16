#include "Engine.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;

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
	Engine *eng = new Engine(WinWidth, WinHeight);
	b2World *World = new b2World(b2Vec2(0, 0));	// Physics Engine
	Texture* texture = new Texture("./Resources/Ship1.bmp", 1, 7);
	Player *player = new Player(3.f, 3.f, 0.0125f, World, texture);
	Scene *sc = new Scene(player, World);	//Game Logic
	eng->init(World, sc);
	eng->run();

	return 0;
}