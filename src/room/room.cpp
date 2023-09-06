//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "ncurses.h"
#include "../game.h"
#include "../entity/entity.h"
#include "iostream"
#include "../entity/room_switch.h"

using namespace std;

Room::Room() : InputListener() {
    this->height = 1;
    this->width = 1;
    this->entities = {};
}

Room::Room(int h, int w) : InputListener() {
    this->height = h;
    this->width = w;
    this->entities = {};
}

Room::Room(int h, int w, vector<Entity*> entities) : InputListener() {
    this->height = h;
    this->width = w;
    this->entities = entities;
}

bool Room::render() {
    if (!changed) {
        return false;
    }
    clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Entity* priority = nullptr;
            for (Entity* entity : entities) {
                if (j + 1 == entity->getX() && i + 1 == entity->getY()) { // Render player
                    if (priority != nullptr && entity->getPriority() > priority->getPriority()) continue;
                    priority = entity;
                }
            }
            if (priority != nullptr) priority->render();
            else printw("0 ");
        }
        printw("\n");
    }
    changed = false;
    return true;
}

void Room::move() {
    for (Entity* entity : entities) {

    }
}

bool Room::isOutsideBounds(int x, int y) {
    return (x > width || x < 1) || (y > height || y < 1);
}

void Room::input(int ch) {

}

void Room::input(int ch, Game* game) {
    if (ch == 'e' || ch == '\n') {
        for (Entity* entity : entities) {
            auto* v = dynamic_cast<RoomSwitch*>(entity);
            if (!v || game->player->getX() != entity->getX() || game->player->getY() != entity->getY()) continue;

            RoomSwitch* partner = v->getPartner();
            game->player->setX(partner->getX());
            game->player->setY(partner->getY());

            removeEntity(game->player);
            v->getConnectedRoom()->addEntity(game->player);
            game->setCurrentRoom(v->getConnectedRoom());
            v->getConnectedRoom()->changed = true;
            printw("switched");
        }
    }
}

void Room::setHeight(int h) {
    height = h;
}

int Room::getHeight() {
    return height;
}

void Room::setWidth(int w) {
    width = w;
}

int Room::getWidth() {
    return width;
}

void Room::addEntity(Entity* entity) {
    this->entities.push_back(entity);
}

void Room::removeEntity(Entity *entity) {
    auto v = remove(this->entities.begin(), this->entities.end(), entity);
    if (v != this->entities.end()) {
        this->entities.erase(v); // Remove the element
    }
}

vector<Entity*> Room::getEntities() {
    return entities;
}