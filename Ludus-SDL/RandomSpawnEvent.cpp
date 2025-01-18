#include "RandomSpawnEvent.h"

IntAndPointer RandomSpawnEvent::call()const{
    std::srand(std::time(0));
    int randomNumber = std::rand() % 21;
    IntAndPointer result;
    result.number = randomNumber;
    std::random_device rd; // Seed for the random number engine
    std::mt19937 gen(rd()); // Mersenne Twister random number engine

    std::uniform_real_distribution<> dis(2, 8);

    if( randomNumber < 3)
        result.pointer = (void *)new Loner( dis(gen) , -3, 0.0125f, World);
    else if( randomNumber < 6)
        result.pointer = (void *)new Rusher( 13, dis(gen), 0.01f, World, true);
    else if( randomNumber < 9)
        result.pointer = (void *)new Rusher( -3, dis(gen), 0.01f, World, false);
    else if( randomNumber < 13)
        result.pointer = (void *)new Drone( dis(gen) , -3, 0.008f, World);
    else if( randomNumber < 18)
        result.pointer = (void *)new Asteroid( dis(gen) , -3, 0.008f, World, std::rand() % 2 ,1 + std::rand() % 3 , 0.0f, 1.5f);
    return result;
}

RandomSpawnEvent::RandomSpawnEvent(float minInterval, float maxInterval, b2World* World) :
    Event(minInterval, maxInterval){
        this->World = World;
    }