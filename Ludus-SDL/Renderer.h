#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <list>
#include <chrono>
#include "Player.h"

class Player;

class Renderer
{
private:
    std::list<Player*> objects;
    b2World* World;
    SDL_Window* Window;
    SDL_GLContext Context;
    uint32_t WindowFlags;
    int elapsed;
    bool Running = true;
    int WinWidth, WinHeight;
    GLuint TextureIdCount;
    void Events(SDL_Event* event);
    GLuint GenerateTexture();
    void Update(float elapsed);



public:
    void Render();
    void init(float dx, float dy);
    Renderer(int WinWidth, int WinHeight);
    void run();
    Player* addObject(float x, float y, float width, float height, const char* image_path);
};
