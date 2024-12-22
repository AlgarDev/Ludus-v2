#include "Player.h"

Player::Player(float x, float y, float width, float height, b2World* World, Texture* texture) 
: Square(x, y, width, height, World, texture){
	this->time = 0;
}

void Player::move(float dx, float dy, float rotation, char movementType) {
	b2Vec2 force(dx,dy);
	switch (movementType)
	{
	case 'f':
		//apply gradual force upwards
		Body->ApplyForce(force, Body->GetWorldCenter(), true);
		break;
	case 'i':
		//apply immediate force upwards
		Body->SetLinearVelocity(force);
		break;
	case 't':
		//teleport or 'warp' to new location
		Body->SetTransform(force, 0);
		break;
	default:
		return;
	}
}

void Player::update(Renderer *renderer, float deltaTime) {
	time += deltaTime;
	if( movement != nullptr )
		movement(this, renderer, deltaTime);
}

void Player::setMovement(std::function<void(Player*,Renderer*,float)> movement) {
	this->movement = movement;
}