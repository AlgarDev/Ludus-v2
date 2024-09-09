#include "Renderer.h"

#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>

GLuint loadTexture()
{
    const unsigned char data[] =
    {
        255,   0,   0,    0, 255,   0,
          0,   0, 255,  255, 255, 255,
    };
    const GLsizei width = 2;
    const GLsizei height = 2;

    GLuint textureID = 0;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    return textureID;
}

Renderer::Renderer(int WinWidth, int WinHeight) {
    this->WinWidth = WinWidth;
    this->WinHeight = WinHeight;
    this->TextureIdCount = 0;
}
GLuint Renderer::GenerateTexture() {
    return TextureIdCount++;
}
void Renderer::init() {
    World = new b2World(b2Vec2(0, 0));
    this->WindowFlags = SDL_WINDOW_OPENGL;
    this->Window = SDL_CreateWindow("Running Ludus", 50, 50, WinWidth, WinHeight, WindowFlags);
    this->Context = SDL_GL_CreateContext(Window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.f, 10.f, 10.f, 0.f, 0.f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glEnable(GL_TEXTURE_2D);
};

Square *Renderer::addObject(float x, float y, float width, float height, const char* image_path) {
    Texture* texture = new Texture(image_path);
    Square* result = new Square(x, y, width, height, World, texture);
    objects.push_front(result);
    return result;

}

void Renderer::Render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::list<Square*>::iterator it;
    for (it = objects.begin(); it != objects.end(); ++it)
        (*it)->render();
    SDL_GL_SwapWindow(Window);
};

void Renderer::Events(SDL_Event* event) {
    while (SDL_PollEvent(event) != 0) {
        // User requests to close the window
        if (event->type == SDL_QUIT) {
            Running = false;
        }
    }
};

void Renderer::run() {
    // Event handler
    SDL_Event event;
    // Main application loop
    while (Running) {
        // Handle events in the queue
        Events(&event);
        Render();
    }
    // Clean up and close the window
    SDL_DestroyWindow(Window);
    SDL_Quit();
}