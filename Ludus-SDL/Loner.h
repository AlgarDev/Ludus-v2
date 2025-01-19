#pragma once
#include "Texture.h"
#include "Square.h"
#include "Explosion.h"
#include "Missile.h"
#include <list>
#include <ctime>

class Loner : public Square
{
public:
	std::list<Explosion*> explosions;
	std::list<Missile*> missiles;
	void Collide(Square* other) override;
	Texture *missileTextures;
	Texture *explosionTexture;
	float time;
	float shootDelay = 0.5f;
	float lastShootTimestamp;
	float lastSpriteUpdateTimestamp;
	Loner(float x, float y, float scale, b2World* World);
	void update(float deltaTime);
	void move();
	void renderWithDependent();
	bool isActive();
	bool isDead();

private:
static Texture* getRandomTexture() {
        // Define a group of textures
        static std::vector<std::string> textureGroup = {
            "./Resources/LonerA.bmp",
            "./Resources/LonerB.bmp",
            "./Resources/LonerC.bmp",
        };

        // Seed random generator (only once)
        static bool seeded = []() {
            std::srand(static_cast<unsigned>(std::time(0)));
            return true;
        }();

        // Randomly pick an index from the group
        int randomIndex = std::rand() % textureGroup.size();

        // Create and return a new Texture object
        return new Texture(textureGroup[randomIndex].c_str(), 4, 4);
    }
	bool canShoot();
	void shoot();
    int hp;

};
