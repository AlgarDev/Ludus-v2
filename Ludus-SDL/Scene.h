#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <list>
#include <chrono>
#include "Player.h"

class Player;

class Scene
{
    public:
    Scene(Player *player, b2World *World);
    void addBackground(Square *background);
    void renderScene();
    void updateScene(float deltaTime);
    void keyboardEvent(SDL_Keycode Key, bool KeyDown);
    void keyboardState(const Uint8* currentKeyStates);

    private:
    Player *player;
    Square *background;
    b2World *World;
};