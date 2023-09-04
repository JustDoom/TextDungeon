//
// Created by doom on 4/09/23.
//

#include "room.h"
#include "iostream"

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
    system("clear"); // Apparently unsafe. look into alternatives
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i + 1 == y && j + 1 == x) { // Render player
                cout << "x";
            } else if (rooms.contains(std::array<int, 2>{j + 1, i + 1})) { // Render room entrances
                cout << "R";
            } else {  // Render floor
                cout << "0";
            }
        }
        cout << endl;
    }
}

bool Room::isOutsideBounds(int x, int y) {
    return (x > width || x < 1) || (y > height || y < 1);
}

Room* Room::handleMovement(string input) {
    // Loop through each move action
    for (char i : input) {
        if (i == 'w') {
            if (isOutsideBounds(x, y - 1)) {
                continue;
            }
            y--;
        } else if (i == 'a') {
            if (isOutsideBounds(x - 1, y)) {
                continue;
            }
            x--;
        } else if (i == 's') {
            if (isOutsideBounds(x, y + 1)) {
                continue;
            }
            y++;
        } else if (i == 'd') {
            if (isOutsideBounds(x + 1, y)) {
                continue;
            }
            x++;
        } else if (i == 'e' && rooms.contains(array<int, 2>{x, y})) {
            // Get the room the player attempts to enter
            Room* room = rooms.at(array<int, 2>{x, y});
            // Loop through the rooms in the next room to find the exit of the current room
            for (auto & it : room->rooms) {
                if (it.second != this) {
                    continue;
                }

                // Set position in next room to the exit
                room->setX(it.first[0]);
                room->setY(it.first[1]);
                break;
            }
            return room;
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

void Room::addRoom(Room* room, int x, int y) {
    array<int, 2> pos {x, y};
    rooms[pos] = room;
}

map<std::array<int, 2>, Room*> Room::getRooms() {
    return rooms;
}