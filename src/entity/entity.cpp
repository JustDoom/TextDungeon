//
// Created by dino on 5/09/23.
//

#include "entity.h"

Entity::Entity(int x, int y) {
    this->x = x;
    this->y = y;
}

void Entity::setX(int x) {
    this->x = x;
}

int Entity::getX() {
    return x;
}

void Entity::setY(int y) {
    this->y = y;
}

int Entity::getY() {
    return y;
}