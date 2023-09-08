//
// Created by dino on 5/09/23.
//

#include "entity.h"

using namespace std;

void Entity::addComponent(shared_ptr<Component> component) {
    component->owner = this;
    components.push_back(component);
}

template <typename T>
shared_ptr<T> Entity::getComponent() {
    for (auto& component : this->components) {
        if (auto casted = std::dynamic_pointer_cast<T>(component)) {
            return casted;
        }
    }
    return nullptr;
}

void Entity::update() {
    for (auto& component : components) {
        //component->update();
    }
}