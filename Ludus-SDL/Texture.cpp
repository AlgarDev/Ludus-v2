#pragma once
#include "Texture.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>

Texture::Texture(const char* image_path) {
    image = SDL_LoadBMP(image_path);
    if (!image) {
        std::cerr << "Error loading image: " << SDL_GetError() << std::endl;
        exit(0);
    }
    glGenTextures(1, &textures);
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image->w, image->h, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void Texture::Apply() {
    glBindTexture(GL_TEXTURE_2D, textures);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

/*
char* image_path = "helloworld.bmp";
int x_pos = 124;
int y_pos = 124;

GLuint mTextureWidth = 124;
GLuint mTextureHeight = 124;

SDL_Surface* image = IMG_Load(image_path);
if (!image)
{
    std::cout << "Error Cannot load image";
}

float x = 450.0f;
float y = 150.0f;
float width = 100.0f;
float height = 100.0f;

float iheight = 124.0f;
float iwidth = 124.0f;


glEnable(GL_TEXTURE_2D);

//glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
GLuint textures;
glGenTextures(1, &textures); //Number of textures stored in array name specified

glBindTexture(GL_TEXTURE_2D, textures);

glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

// Map the surface to the texture in video memory
glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 124, 124, 0, GL_RGB, GL_UNSIGNED_BYTE, image->pixels); //GL_BITMAP
SDL_FreeSurface(image);


glBindTexture(GL_TEXTURE_2D, textures);

//Render texture quad
glBegin(GL_QUADS);
glTexCoord2f(0.f, 0.f); glVertex2f(x, y); //Bottom left
glTexCoord2f(1.f, 0.f); glVertex2f(x + iwidth, y); //Bottom right
glTexCoord2f(1.f, 1.f); glVertex2f(x + iwidth, y + iheight); //Top right
glTexCoord2f(0.f, 1.f); glVertex2f(x, y + iheight); //Top left
glEnd();

glDisable(GL_TEXTURE_2D);


glPopMatrix(); //End rendering phase
*/