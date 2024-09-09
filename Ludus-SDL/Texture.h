#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
class Texture
{
public:
    Texture(const char* image_path);
    void Apply();
private:
    GLuint textures;
    SDL_Surface* image;
};