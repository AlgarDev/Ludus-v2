#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Texture.h"


class Hud
{
public:
	void render();
	Hud(float x, float y, float w, float h, Texture* texture, const char* text);
	Hud(float x, float y, float w, float h, Texture* texture, int number, int numberOfDigits);
	~Hud();
    void setNumber(int number);
    void setString(char *text);
    int getNumber();

private:
    void renderNumber();
    void renderText();
    void renderSquare(float offset_x, float offset_y);
    void setTextureNumber(int number);
    void setTextureText(char letter);
    float x,y,w,h;
    int numberDisplay, numberOfDigits;
    const char *textDisplay;
    bool isNumber, isString;
	Texture* texture;
};
