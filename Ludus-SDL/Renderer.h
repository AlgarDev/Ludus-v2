#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <list>
#include "Square.h"
class Renderer
{
private:
    std::list<Square*> objects;
    b2World* World;
    SDL_Window* Window;
    SDL_GLContext Context;
    uint32_t WindowFlags;
    bool Running = true;
    int WinWidth, WinHeight;
    GLuint TextureIdCount;
    void Render();
    void Events(SDL_Event* event);
    GLuint GenerateTexture();


public:
    void init();
    Renderer(int WinWidth, int WinHeight);
    void run();
    Square *addObject(float x, float y, float width, float height, const char* image_path);
};
