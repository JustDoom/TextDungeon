//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "iostream"
#include "ncurses.h"

using namespace std;

Room::Room() {
    height = 0;
    width = 0;
    x = 0;
    y = 0;
    rooms = {};

}

Room::Room(int h, int w, int x, int y) {
    height = h;
    width = w;
    this->x = x;
    this->y = y;
    rooms = {};
}

bool Room::render() {
    if (!changed) return false;
    changed = false;
    clear();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i + 1 == y && j + 1 == x) { // Render player
                printw("X ");
            } else if (rooms.contains(std::array<int, 2>{j + 1, i + 1})) { // Render room entrances
                printw("R ");
            } else {  // Render floor
                printw("0 ");
            }
        }
        printw("\n");
    }
    return true;
}

bool Room::isOutsideBounds(int x, int y) {
    return (x > width || x < 1) || (y > height || y < 1);
}

Room *Room::handleMovement(int input) {
    if (input == 'w' || input == KEY_UP) {
        if (isOutsideBounds(x, y - 1)) {
            return this;
        }
        y--;
        changed = true;
    } else if (input == 'a' || input == KEY_LEFT) {
        if (isOutsideBounds(x - 1, y)) {
            return this;
        }
        x--;
        changed = true;
    } else if (input == 's' || input == KEY_DOWN) {
        if (isOutsideBounds(x, y + 1)) {
            return this;
        }
        y++;
        changed = true;
    } else if (input == 'd' || input == KEY_RIGHT) {
        if (isOutsideBounds(x + 1, y)) {
            return this;
        }
        x++;
        changed = true;
    }
    return this;
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

void Room::setX(int x) {
    this->x = x;
}

int Room::getX() {
    return x;
}

void Room::setY(int y) {
    this->y = y;
}

int Room::getY() {
    return y;
}

void Room::addRoom(Room *room, int x, int y) {
    array<int, 2> pos{x, y};
    rooms[pos] = room;
}

map<std::array<int, 2>, Room *> Room::getRooms() {
    return rooms;
}