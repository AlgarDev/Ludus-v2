#include "Event.h"

Event::Event(float minInterval, float maxInterval)
    : time(0), nextCall(0), dist(minInterval, maxInterval) {
    std::random_device rd;
    gen = std::mt19937(rd()); // Seed the generator
}

bool Event::canBeCalled(float deltaTime){
    time += deltaTime;
    if(time >= nextCall){
        nextCall = time + dist(gen);
        return true;
    }
    return false;
}