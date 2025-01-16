#pragma once
#include <SDL.h>
#include <SDL_opengl.h>
#include <Box2D/Box2D.h>
#include <iostream>
#include <functional>
#include "Square.h"

class ContactListener : public b2ContactListener {
public:
    void BeginContact(b2Contact* contact) override {
        // Get the fixtures involved in the contact
        b2Fixture* fixtureA = contact->GetFixtureA();
        b2Fixture* fixtureB = contact->GetFixtureB();

        // Get the bodies from the fixtures
        b2Body* bodyA = fixtureA->GetBody();
        b2Body* bodyB = fixtureB->GetBody();

        // Get the user data from the bodies (which should be Square objects)
        Square* squareA = (Square*)(bodyA->GetUserData().pointer);
        Square* squareB = (Square*)(bodyB->GetUserData().pointer);

        // If both squares are valid and collide, call Collidle
        if (squareA && squareB) {
            squareA->Collide(squareB);
            squareB->Collide(squareA);
        }
    }

    // Optionally implement other methods (EndContact, PreSolve, PostSolve) if needed
};