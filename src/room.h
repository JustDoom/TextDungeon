//
// Created by doom on 4/09/23.
//

#ifndef TEXTDUNGEON_ROOM_H
#define TEXTDUNGEON_ROOM_H

#include <string>
#include <map>
#include "vector"

class Room {
private:
    int height;
    int width;

    int x;
    int y;

    std::map<std::array<int, 2>, Room*> rooms;

public:
    Room();
    Room(int h, int w, int x, int y);

    // Methods
    void render();
    bool isOutsideBounds(int x, int y);
    Room* handleMovement(std::string input);

    // Getters and Setters
    void setHeight(int h);
    int getHeight();
    void setWidth(int w);
    int getWidth();
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    void addRoom(Room &room, int x, int y);
    std::map<std::array<int, 2>, Room*> getRooms();
};

#endif