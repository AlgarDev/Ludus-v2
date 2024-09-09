#pragma once
#include "Renderer.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;

void testDefineMovement(Square* entity, Renderer* renderer, float deltaTime) {
	entity->time += deltaTime;
	const float amplitude = 10.0f; // Maximum force applied
	const float frequency = 1.f; // Frequency of oscillation in Hz
	// Calculate the sinusoidal force
	float force = amplitude * sinf(2.0f * M_PI * frequency * entity->time);
	printf("%f\n", deltaTime);

	entity->move(force, 0.0f, 0.0f, 'i');
}

int main() {
	Renderer *render = new Renderer(WinWidth, WinHeight);
	render->init(0, 0); //Gravidade X e Gravidade Y
	Square *pointerToObject = render->addObject(8.f, 3.f, 1.f, 1.f, "./Resources/Burner1.bmp");

	Square* PointerToAnotherObject = render->addObject(1.f, 1.f, 2.f, 5.f, "./Resources/Xlogo.bmp");
	PointerToAnotherObject->setMovement(testDefineMovement);
	render->run();

	return 0;
}