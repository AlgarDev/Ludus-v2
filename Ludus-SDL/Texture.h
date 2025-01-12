#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>

class Texture
{
public:
    Texture(const char* image_path, int numberOfRows, int numberOfColumns);
    void Apply();
    void moveSprite(int row, int column);
    void cycleLeft();
    void cycleRigth();
    void fulllCycle();
    GLuint textures;
    SDL_Surface* image;
    float spriteWidth;
    int spriteColumn;
    int spriteRow;
    int numberOfColumns;
    int numberOfRows;
    float spriteHeight;
};