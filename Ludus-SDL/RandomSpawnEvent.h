#pragma once
#include "Event.h"
#include "Loner.h"
#include <ctime>

class RandomSpawnEvent : public Event
{
public:
	RandomSpawnEvent(float minInterval, float maxInterva, b2World* World);
	IntAndPointer call()const override;

private:
b2World *World;
};
