//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "iostream"
#include "ncurses.h"

Room::Room() {
    this->height = 0;
    this->width = 0;
    this->rooms = {};
    this->entities = {};
}

Room::Room(int h, int w) {
    this->height = h;
    this->width = w;
    this->rooms = {};
    this->entities = {};
}

Room::Room(int h, int w, vector<Entity> entities) {
    this->height = h;
    this->width = w;
    this->rooms = {};
    this->entities = entities;
}

bool Room::render() {
    if (!changed) return false;
    changed = false;
    clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (Entity entity : entities) {
                if (i + 1 == entity.getX() && j + 1 == entity.getY()) { // Render player
                    printw("X ");
                } else if (rooms.contains(std::array<int, 2>{j + 1, i + 1})) { // Render room entrances
                    printw("R ");
                } else {  // Render floor
                    printw("0 ");
                }
            }
        }
        printw("\n");
    }
    return true;
}

bool Room::isOutsideBounds(int x, int y) {
    return (x > width || x < 1) || (y > height || y < 1);
}

Room::

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

void Room::addRoom(Room *room, int x, int y) {
    array<int, 2> pos{x, y};
    rooms[pos] = room;
}

map<std::array<int, 2>, Room *> Room::getRooms() {
    return rooms;
}

void Room::addEntity(Entity entity) {
    this->entities.emplace_back(entity);
}

vector<Entity> Room::getEntities() {
    return entities;
}