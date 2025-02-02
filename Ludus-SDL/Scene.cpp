#include "Scene.h"

Scene::Scene(Player *player, b2World *World){
    this->player = player;
    this->World = World;
}

void Scene::updateScene(float deltaTime){
    if(!player->isDead())
        player->update(deltaTime);
    for(Explosion *explosion : explosions) explosion->update(deltaTime);
    for(Event* event : events)  if(event->canBeCalled(deltaTime))   handleEvent(event->call());
    for(Loner* loner : loners) {
        loner->update(deltaTime);
        if(loner->isDead()){
            explosions.push_back(new Explosion(loner->getX(), loner->getY(), 0.01f, this->World, new Texture("./Resources/explode64.bmp", 2, 5)));
        }
    }
    for(Rusher* rusher : rushers) {
        rusher->update(deltaTime);
        if(rusher->isDead()){
            explosions.push_back(new Explosion(rusher->getX(), rusher->getY(), 0.005f , this->World, new Texture("./Resources/explode64.bmp", 2, 5)));
        }
    }
    clearData();
}

void Scene::clearData(){
    rushers.remove_if([](Rusher* rusher) {
		if(!rusher->isActive()){
			delete rusher;
			return true;
		}
		return false;
	});
    loners.remove_if([](Loner* loner) {
		if(!loner->isActive()){
			delete loner;
			return true;
		}
		return false;
	});
    explosions.remove_if([](Explosion* explosion) {
		if(!explosion->isActive()){
			delete explosion;
			return true;
		}
		return false;
	});
}

void Scene::handleEvent(IntAndPointer eventResult){
    if(eventResult.number < 3){
        loners.push_back((Loner *) eventResult.pointer);
        printf("Loner Spawn Event\n");
    }else if(eventResult.number < 6){
        rushers.push_back((Rusher *) eventResult.pointer);
        printf("Rusher Spawn Event LEFT\n");
    }else if(eventResult.number < 9){
        rushers.push_back((Rusher *) eventResult.pointer);
        printf("Rusher Spawn Event RIGTH\n");
    }
    else
        printf("Nothing Event\n");
}


void Scene::renderScene(){
    background->render();
    for(Loner* loner : loners) loner->renderWithDependent();
    for(Rusher* rusher : rushers) rusher->render();
    for(Explosion* explosion : explosions) explosion->render();
    if(!player->isDead())
        player->renderWithDependent();
}
void Scene::keyboardEvent(SDL_Keycode Key, bool KeyDown){
    player->setAction(Key, KeyDown);
}
void Scene::keyboardState(const Uint8* currentKeyStates){
    player->useKeyboardState(currentKeyStates);
}

void Scene::addEvent(Event * event){
    this->events.push_back( event );
}


void Scene::addBackground(Square *background){
    this->background = background;
}