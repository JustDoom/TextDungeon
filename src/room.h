//
// Created by doom on 4/09/23.
//

#ifndef TEXTDUNGEON_ROOM_H
#define TEXTDUNGEON_ROOM_H

#include <map>
#include "vector"
#include "array"
#include "entity/entity.h"
#include "listener/input_listener.h"
#include "game.h"

using namespace std;

class Room : public InputListener {
private:
    int height;
    int width;

    map<array<int, 2>, Room*> rooms;

    vector<Entity> entities;


public:
    //static Game* game;

    Room();
    Room(int h, int w);
    Room(int h, int w, vector<Entity> entities);

    bool changed = true;

    // Methods
    bool render();
    void move();
    bool isOutsideBounds(int x, int y);

    void input(int ch) override;

    // Getters and Setters
    void setHeight(int h);
    int getHeight();
    void setWidth(int w);
    int getWidth();
    void addRoom(Room* room, int x, int y);
    map<array<int, 2>, Room*> getRooms();
    void addEntity(Entity entity);
    vector<Entity> getEntities();
};

#endif