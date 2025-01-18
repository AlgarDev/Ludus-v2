#include "RandomSpawnEvent.h"

IntAndPointer RandomSpawnEvent::call()const{
    std::srand(std::time(0));
    int randomNumber = std::rand() % 11;
    IntAndPointer result;
    result.number = randomNumber;
    if( randomNumber < 3)
        result.pointer = (void *)new Loner( static_cast<float>( 2+(std::rand()) / RAND_MAX * 7) , -3, 0.0125f, World);
    else if( randomNumber < 6)
        result.pointer = (void *)new Rusher( 13, static_cast<float>( 2+(std::rand()) / RAND_MAX * 7), 0.01f, World, true);
    else if( randomNumber < 9)
        result.pointer = (void *)new Rusher( -3, static_cast<float>( 2+(std::rand()) / RAND_MAX * 7), 0.01f, World, false);
    return result;
}

RandomSpawnEvent::RandomSpawnEvent(float minInterval, float maxInterval, b2World* World) :
    Event(minInterval, maxInterval){
        this->World = World;
    }