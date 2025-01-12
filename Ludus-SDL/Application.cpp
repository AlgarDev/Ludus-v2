#include "Renderer.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;

/*
void testDefineMovement(Player* entity, Renderer* renderer, float deltaTime) {
	entity->time += deltaTime;
	const float amplitude = 3.0f; // Maximum force applied
	const float frequency = 1.f; // Frequency of oscillation in Hz
	// Calculate the sinusoidal force
	float force = amplitude * sin(frequency * entity->time);
	entity->move(force, 0.0f, 0.0f, 'i');
}
*/
int main() {
	Renderer *render = new Renderer(WinWidth, WinHeight);
	render->init(0, 0); //Gravidade X e Gravidade Y
	Player *pointerToObject = (Player*)render->addObject(3.f, 3.f, 0.0125f, "./Resources/Ship1.bmp", 1, 1, 7);
	//pointerToObject->setMovement(testDefineMovement);
	render->run();

	return 0;
}