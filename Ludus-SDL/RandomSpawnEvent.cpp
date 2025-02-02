#include "RandomSpawnEvent.h"

IntAndPointer RandomSpawnEvent::call() const {
    // Reuse the generator initialized in the constructor
    std::uniform_int_distribution<> randomNumberDist(0, 9); // For the random number (0 to 20)
    std::uniform_real_distribution<> dis(2, 8);             // For the floating-point range

    int randomNumber = randomNumberDist(gen); // Generate a random number
    IntAndPointer result;
    result.number = randomNumber;

    if (randomNumber < 3) {
        result.pointer = (void*)new Loner(dis(gen), -3, 0.0125f, World);
    } else if (randomNumber < 6) {
        result.pointer = (void*)new Rusher(13, dis(gen), 0.01f, World, true);
    } else if (randomNumber < 9) {
        result.pointer = (void*)new Rusher(-3, dis(gen), 0.01f, World, false);
    }
    return result;
}

RandomSpawnEvent::RandomSpawnEvent(float minInterval, float maxInterval, b2World* World) 
    : Event(minInterval, maxInterval), World(World), gen(std::random_device{}()) // Initialize the generator here
{
    // Empty constructor body
}