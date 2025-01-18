#include "Scene.h"

Scene::Scene(Player *player, b2World *World){
    this->player = player;
    this->World = World;
}

void Scene::updateScene(float deltaTime){
    player->update(deltaTime);
    
    for(Event* event : events)  if(event->canBeCalled(deltaTime))   handleEvent(event->call());
    for(Loner* loner : loners) loner->update(deltaTime);
    for(Rusher* rusher : rushers) rusher->update(deltaTime);
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