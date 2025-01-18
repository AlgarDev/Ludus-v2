#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <list>
#include <chrono>
#include "Player.h"
#include "Square.h"
#include "Scene.h"
#include <thread>


class Player;
class Scene;

class Engine
{
private:
    b2World* World;
    SDL_Window* Window;
    SDL_GLContext Context;
    uint32_t WindowFlags;
    int elapsed;
    bool Running = true;
    int WinWidth, WinHeight;
    void Events(SDL_Event* event);
    void Update(float elapsed);
    Scene *currentScene;



public:
    b2World* getWorld();
    void addRender(Square* objectToRender);
    void Render();
    void init(b2World* World, Scene *scene);
    Engine(int WinWidth, int WinHeight);
    void run();
};
