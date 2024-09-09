#include "Renderer.h"

Renderer::Renderer(int WinWidth, int WinHeight) {
    this->WinWidth = WinWidth;
    this->WinHeight = WinHeight;
    this->TextureIdCount = 0;
}
GLuint Renderer::GenerateTexture() {
    return TextureIdCount++;
}
void Renderer::init(float dx, float dy) {
    World = new b2World(b2Vec2(dx, dy));
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

Square* Renderer::addObject(float x, float y, float width, float height, const char* image_path) {
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

void Renderer::Update(float elapsed) {
    std::list<Square*>::iterator it;
    for (it = objects.begin(); it != objects.end(); ++it)
        (*it)->update(this, elapsed);
}

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
    const int VELOCITY_ITERAIONS = 6;
    const int POSITION_ITERATION = 2;
    double elapsed = 1;
    while (Running) {
        // Handle events in the queue
        auto start = std::chrono::high_resolution_clock::now();
        Events(&event);
        Update(elapsed);
        Render();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = end - start;
       elapsed = duration.count() / 1000.0;
        World->Step(elapsed, VELOCITY_ITERAIONS, POSITION_ITERATION);
    }
    // Clean up and close the window
    SDL_DestroyWindow(Window);
    SDL_Quit();
}