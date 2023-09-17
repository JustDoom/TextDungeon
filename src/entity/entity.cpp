//
// Created by dino on 5/09/23.
//

#include "entity.h"

using namespace std;

class Entity;

void Entity::addComponent(std::shared_ptr<Component> component) {
    component->owner = this;
    components.push_back(component);
}



void Entity::update() {
    for (auto& component : components) {
        //component->update();
    }
}