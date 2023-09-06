//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "ncurses.h"
#include "../game.h"
#include "../entity/entity.h"
#include "iostream"

using namespace std;

Room::Room() : InputListener() {
    this->height = 0;
    this->width = 0;
    this->rooms = {};
    this->entities = {};
}

Room::Room(int h, int w) : InputListener() {
    this->height = h;
    this->width = w;
    this->rooms = {};
    this->entities = {};
}

Room::Room(int h, int w, vector<Entity*> entities) : InputListener() {
    this->height = h;
    this->width = w;
    this->rooms = {};
    this->entities = entities;
}

bool Room::render() {
    if (!changed) {
        return false;
    }
    clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (Entity* entity : entities) {
                if (j + 1 == entity->getX() && i + 1 == entity->getY()) { // Render player
                    entity->render();
                    break;
                } else if (rooms.contains(array<int, 2>{j + 1, i + 1})) { // Render room entrances
                    attron(COLOR_PAIR(3) | A_BOLD);
                    printw("R ");
                    attroff(COLOR_PAIR(3) | A_BOLD);
                } else {  // Render floor
                    printw("0 ");
                }
            }
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
    if (game->getCurrentRoom() != this) return;
    if ((ch == 'e' || ch == '\n') && rooms.contains(array<int, 2>{game->player->getX(), game->player->getY()})) {
        // Get the room the player attempts to enter
        Room *room = rooms.at(array<int, 2>{game->player->getX(), game->player->getY()});
        // Loop through the rooms in the next room to find the exit of the current room
        for (auto &it: room->getRooms()) {
            if (it.second != this) {
                continue;
            }

            // Set position in next room to the exit
            game->player->setX(it.first[0]);
            game->player->setY(it.first[1]);
            break;
        }
        room->addEntity(game->player);
        removeEntity(game->player);
        game->setCurrentRoom(room);
        room->changed = true;
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

void Room::addRoom(Room *room, int x, int y) {
    array<int, 2> pos{x, y};
    rooms[pos] = room;
}

map<array<int, 2>, Room *> Room::getRooms() {
    return rooms;
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