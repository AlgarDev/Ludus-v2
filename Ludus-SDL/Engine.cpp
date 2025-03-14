#include "Engine.h"

Engine::Engine(int WinWidth, int WinHeight) {
    this->WinWidth = WinWidth;
    this->WinHeight = WinHeight;
}

void Engine::init(b2World* World, Scene *scene) {
    this->World = World;
    this->currentScene = scene;
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

void Engine::Render() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    currentScene->renderScene();
    SDL_GL_SwapWindow(Window);
};

void Engine::Update(float elapsed) {
    currentScene->updateScene(elapsed);
}

void Engine::Events(SDL_Event* event) {
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    currentScene->keyboardState(currentKeyStates);
    while (SDL_PollEvent(event) != 0) {
        // User requests to close the window
        if (event->type == SDL_QUIT) {
            Running = false;
        }
        if (event->type == SDL_KEYDOWN) {
            currentScene->keyboardEvent(event->key.keysym.sym, true);
        }
        // Handle keyup events (optional)
        if (event->type == SDL_KEYUP) {
            currentScene->keyboardEvent(event->key.keysym.sym, false);
        }
    }
};

void Engine::run() {
    // Event handler
    constexpr double targetFrameTime = 1.0 / 60.0;
    SDL_Event event;
    // Main application loop
    const int VELOCITY_ITERATIONS = 8;
    const int POSITION_ITERATIONS = 3;
    double elapsed = 0;
    auto lastIteration = std::chrono::high_resolution_clock::now();
    double fixedStep = 0.01666;
    //double frameCount = 0;
    //double totalTime = 0;
    double accumulator = 0;
    while (Running) {
        auto currentIteration = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = currentIteration - lastIteration;
        elapsed = duration.count();
        accumulator += elapsed;
        while (accumulator >= fixedStep) {
            World->Step(fixedStep, VELOCITY_ITERATIONS, POSITION_ITERATIONS); //Physics Engine (Collisions/Movement)
            accumulator -= fixedStep;
        }
        Events(&event);     //Keyboard
        Update(elapsed);    //Update Scene
        Render();           //Render Scene
        //frameCount++;
        lastIteration = currentIteration;
        //totalTime += elapsed;
        if (elapsed < targetFrameTime) std::this_thread::sleep_for(std::chrono::duration<double>(targetFrameTime - elapsed));
        //printf("CurrentFrameRate : %f\n", frameCount / (totalTime + 1e-9));
    }
    // Clean up and close the window
    SDL_DestroyWindow(Window);
    SDL_Quit();
}