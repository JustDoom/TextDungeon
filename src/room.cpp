//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "ncurses.h"
#include "game.h"
#include "entity/entity.h"

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

Room::Room(int h, int w, vector<Entity> entities) : InputListener() {
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
                } else if (rooms.contains(array<int, 2>{j + 1, i + 1})) { // Render room entrances
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

void Room::move() {
    for (Entity entity : entities) {

    }
}

bool Room::isOutsideBounds(int x, int y) {
    return (x > width || x < 1) || (y > height || y < 1);
}

void Room::input(int ch) {
    Game* game;
    game = new Game;
    if (game->getCurrentRoom() != this) return; // TODO: do something to only send it to the players room
    if ((ch == 'e' || ch == '\n') && rooms.contains(array<int, 2>{game->player->getX(), game->player->getY()})) {
        // Get the room the player attempts to enter
        Room *room = rooms.at(array<int, 2>{game->player->getX(), game->player->getY()});
        // Loop through the rooms in the next room to find the exit of the current room
        for (auto &it: room->getRooms()) {
            if (it.second != game->getCurrentRoom()) {
                continue;
            }

            // Set position in next room to the exit
            game->player->setX(it.first[0]);
            game->player->setY(it.first[1]);
            break;
        }
        game->getCurrentRoom()->changed = true;
//        currentRoom->changed = true;
        game->setCurrentRoom(room);
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

void Room::addEntity(Entity entity) {
    this->entities.emplace_back(entity);
}

vector<Entity> Room::getEntities() {
    return entities;
}