//
// Created by dino on 6/09/23.
//

#include "menu_component.h"

MenuComponent::MenuComponent() {
    this->entities = {};
}

MenuComponent::MenuComponent(vector<Entity*> entities) {
    this->entities = entities;
}

void MenuComponent::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

void MenuComponent::removeEntity(Entity *entity) {
    auto v = remove(this->entities.begin(), this->entities.end(), entity);
    if (v != this->entities.end()) {
        this->entities.erase(v); // Remove the element
    }
}

vector<Entity*> MenuComponent::getEntities() {
    return entities;
}