//
// Created by doom on 4/09/23.
//

#include "room_component.h"
#include "iostream"

using namespace std;

RoomComponent::RoomComponent() {
    this->height = 1;
    this->width = 1;
    this->entities = {};
}

RoomComponent::RoomComponent(int h, int w) {
    this->height = h;
    this->width = w;
    this->entities = {};
}

RoomComponent::RoomComponent(int h, int w, vector<Entity*> entities) {
    this->height = h;
    this->width = w;
    this->entities = entities;
}

void RoomComponent::update() {
}

void RoomComponent::setHeight(int h) {
    height = h;
}

int RoomComponent::getHeight() {
    return height;
}

void RoomComponent::setWidth(int w) {
    width = w;
}

int RoomComponent::getWidth() {
    return width;
}

void RoomComponent::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

void RoomComponent::removeEntity(Entity *entity) {
    auto v = remove(this->entities.begin(), this->entities.end(), entity);
    if (v != this->entities.end()) {
        this->entities.erase(v); // Remove the element
    }
}

vector<Entity*> RoomComponent::getEntities() {
    return entities;
}