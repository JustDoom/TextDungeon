//
// Created by doom on 4/09/23.
//

#include "iostream"
#include "room.h"

using namespace std;

Room::Room() {
    height = 0;
    width = 0;
    x = 0;
    y = 0;
}

Room::Room(int h, int w, int x, int y) {
    height = h;
    width = w;
    this->x = x;
    this->y = y;
}

void Room::render() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i + 1 == y && j + 1 == x) {
                cout << "x";
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

void Room::handleMovement(string input) {
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