#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include "Renderer.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;
int main() {
	Renderer *render = new Renderer(WinWidth, WinHeight);
	render->init();
	Square *pointerToObject = render->addObject(-0.5f, -0.5f, 4.f, 4.f, "./Resources/Burner1.bmp");
	Square* PointerToAnotherObject = render->addObject(1.f, 1.f, 2.f, 5.f, "./Resources/Xlogo.bmp");
	render->run();

	return 0;
}