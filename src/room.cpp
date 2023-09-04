//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "iostream"
#include "vector"

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

void Room::render() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i + 1 == y && j + 1 == x) {
                cout << "x";
            } else if (rooms.contains(std::array<int, 2>{j + 1, i + 1})) {
                cout << "R";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
}

bool Room::isOutsideBounds(int x, int y) {
    if (x > width || x < 1) {
        return true;
    }
    if (y > height || y < 1) {
        return true;
    }
    return false;
}

Room* Room::handleMovement(string input) {
    for (char i : input) {
        if (i == 'w') {
            if (isOutsideBounds(x, y - 1)) continue;
            y--;
        } else if (i == 'a') {
            if (isOutsideBounds(x - 1, y)) continue;
            x--;
        } else if (i == 's') {
            if (isOutsideBounds(x, y + 1)) continue;
            y++;
        } else if (i == 'd') {
            if (isOutsideBounds(x + 1, y)) continue;
            x++;
        } else if (i == 'e' && rooms.contains(array<int, 2>{x, y})) {
            return rooms.at(array<int, 2>{x, y});
        }
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

void Room::addRoom(Room &room, int x, int y) {
    array<int, 2> pos {x, y};
    rooms[pos] = &room;
}