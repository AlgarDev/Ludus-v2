#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <box2d/box2d.h>
#include <iostream>
#include "Renderer.h"
#undef main

const int WinWidth = 480;
const int WinHeight = 640;
int main() {
	Renderer *render = new Renderer(WinWidth, WinHeight);
	render->run();
	return 0;
}