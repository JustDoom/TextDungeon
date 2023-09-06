//
// Created by doom on 4/09/23.
//

#ifndef TEXTDUNGEON_ROOM_H
#define TEXTDUNGEON_ROOM_H

#include <map>
#include "vector"
#include "array"
#include "../entity/entity.h"
#include "../listener/input_listener.h"
#include "../game.h"

using namespace std;

class Game;
class InputListener;

class Room : public InputListener {
private:
    int height;
    int width;

    vector<Entity*> entities;

public:
    Room();
    Room(int h, int w);
    Room(int h, int w, vector<Entity*> entities);

    bool changed = true;

    // Methods
    bool render();
    void move();
    bool isOutsideBounds(int x, int y);

    void input(int ch) override;
    void input(int ch, Game* game);

    // Getters and Setters
    void setHeight(int h);
    int getHeight();
    void setWidth(int w);
    int getWidth();
    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    vector<Entity*> getEntities();
};

#endif