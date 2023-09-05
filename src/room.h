//
// Created by doom on 4/09/23.
//

#ifndef TEXTDUNGEON_ROOM_H
#define TEXTDUNGEON_ROOM_H

#include <string>
#include <map>
#include "vector"
#include "entity/entity.h"

using namespace std;

class Room {
private:
    int height;
    int width;

    map<std::array<int, 2>, Room*> rooms;
    vector<Entity> entities;

public:
    Room();
    Room(int h, int w);
    Room(int h, int w, vector<Entity> entities);

    bool changed = true;

    // Methods
    bool render();
    bool isOutsideBounds(int x, int y);

    // Getters and Setters
    void setHeight(int h);
    int getHeight();
    void setWidth(int w);
    int getWidth();
    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
    void addRoom(Room* room, int x, int y);
    std::map<std::array<int, 2>, Room*> getRooms();
    void addEntity(Entity entity);
    vector<Entity> getEntities();
};

#endif