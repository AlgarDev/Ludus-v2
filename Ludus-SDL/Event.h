#pragma once
#include <functional>
#include <random>

struct IntAndPointer {
    int number;   // Integer member
    void* pointer; // Void pointer member
    };

class Event
{
public:
	Event(float minInterval, float maxInterval);
    virtual IntAndPointer call() const{
        printf("Nothing\n");
        IntAndPointer result;
	    result.number = 0;
	    result.pointer = (void*)nullptr;
	    return result;
    }
    bool canBeCalled(float deltaTime);
protected:
    float time;
    float nextCall;
    std::mt19937 gen; // Random number generator
    std::uniform_real_distribution<float> dist; // Random interval distribution
};