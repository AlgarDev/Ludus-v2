#include <iostream>
#include <SDL.h>
#include <stdio.h>
#include <box2d/box2d.h>
#include <vector>
#undef main

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create an SDL Window
    SDL_Window* window = SDL_CreateWindow("Simple SDL Window",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Main loop flag
    bool running = true;

    // Event handler
    SDL_Event event;

    // Main application loop
    while (running) {
        // Handle events in the queue
        while (SDL_PollEvent(&event) != 0) {
            // User requests to close the window
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Clear the screen with a color (optional)
        SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));  // Fill with black
        SDL_UpdateWindowSurface(window);
    }

    // Clean up and close the window
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


//TESTE BOX2D

//#include <Box2D/Box2D.h>
//#include <iostream>
//
//int main() {
//    // Define the gravity vector (downwards with magnitude 9.8 m/s^2)
//    b2Vec2 gravity(0.0f, -9.8f);
//
//    // Create the Box2D world with gravity
//    b2World world(gravity);
//
//    // Define the ground body (static body, it doesn't move)
//    b2BodyDef groundBodyDef;
//    groundBodyDef.position.Set(0.0f, -10.0f);  // Place ground 10 units below the origin
//
//    // Create the ground body
//    b2Body* groundBody = world.CreateBody(&groundBodyDef);
//
//    // Define the ground shape as a box (ground width 50, height 10)
//    b2PolygonShape groundBox;
//    groundBox.SetAsBox(50.0f, 10.0f);
//
//    // Attach the shape to the ground body
//    groundBody->CreateFixture(&groundBox, 0.0f);
//
//    // Define the dynamic body (this will be a falling box)
//    b2BodyDef dynamicBodyDef;
//    dynamicBodyDef.type = b2_dynamicBody;  // Dynamic means it will be affected by physics
//    dynamicBodyDef.position.Set(0.0f, 4.0f);  // Initial position 4 units above the ground
//
//    // Create the dynamic body
//    b2Body* dynamicBody = world.CreateBody(&dynamicBodyDef);
//
//    // Define the dynamic shape as a box (1x1 size)
//    b2PolygonShape dynamicBox;
//    dynamicBox.SetAsBox(1.0f, 1.0f);
//
//    // Define the fixture for the dynamic body (density, friction)
//    b2FixtureDef fixtureDef;
//    fixtureDef.shape = &dynamicBox;
//    fixtureDef.density = 1.0f;  // Mass density
//    fixtureDef.friction = 0.3f;  // Friction
//
//    // Attach the fixture to the dynamic body
//    dynamicBody->CreateFixture(&fixtureDef);
//
//    // Simulate the world for 60 steps with a time step of 1/60th of a second (60 Hz)
//    float timeStep = 1.0f / 60.0f;
//    int32 velocityIterations = 6;
//    int32 positionIterations = 2;
//
//    // Simulate for 60 frames
//    for (int32 i = 0; i < 60; ++i) {
//        // Step the world
//        world.Step(timeStep, velocityIterations, positionIterations);
//
//        // Get the position of the dynamic body (the falling box)
//        b2Vec2 position = dynamicBody->GetPosition();
//        float angle = dynamicBody->GetAngle();
//
//        // Print the position and angle
//        std::cout << "Step " << i << ": Box position (" << position.x << ", " << position.y << ") and angle " << angle << std::endl;
//    }
//
//    return 0;
//}

//TESTE OPENGL

//#include <GLFW/glfw3.h>
//
//int main(void)
//{
//    GLFWwindow* window;
//
//    /* Initialize the library */
//    if (!glfwInit())
//        return -1;
//
//    /* Create a windowed mode window and its OpenGL context */
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        glfwTerminate();
//        return -1;
//    }
//
//    /* Make the window's context current */
//    glfwMakeContextCurrent(window);
//
//    /* Loop until the user closes the window */
//    while (!glfwWindowShouldClose(window))
//    {
//        /* Render here */
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        /* Swap front and back buffers */
//        glfwSwapBuffers(window);
//
//        /* Poll for and process events */
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}