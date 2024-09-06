#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <box2d/box2d.h>
#include <iostream>
class Renderer
{
private:
    SDL_Window* Window;
    SDL_GLContext Context;
    uint32_t WindowFlags;
    bool Running = true;
    int WinWidth, WinHeight;
    GLuint TextureIdCount;
    void init();
    void Render();
    void Events(SDL_Event* event);
    GLuint GenerateTexture();


public:
    Renderer(int WinWidth, int WinHeight);
    void run();
};
