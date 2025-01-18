#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <string>
#include <cstring>

class Texture
{
public:
    Texture(const char* image_path, int numberOfRows, int numberOfColumns);
    Texture(std::string image_path, int numberOfRows, int numberOfColumns);
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
private:
    int distance(Uint8 x, Uint8 y, Uint8 z, Uint8 x2, Uint8 y2, Uint8 z2);
};