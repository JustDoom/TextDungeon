//
// Created by doom on 4/09/23.
//

#ifndef TEXTDUNGEON_ROOM_COMPONENT_H
#define TEXTDUNGEON_ROOM_COMPONENT_H

#include <map>
#include "vector"
#include "array"
#include "../entity/entity.h"
#include "../game.h"
#include "component.h"

using namespace std;

class Game;

class RoomComponent : public Component {
private:
    // TODO: Switch this with a system to allow cool shaped rooms
    // possibly use the list of entities and include the ground as one or something
    int height;
    int width;

    vector<Entity*> entities;

public:
    RoomComponent();
    RoomComponent(int h, int w);
    RoomComponent(int h, int w, vector<Entity*> entities);

    // Methods
    void update() override;
    bool isOutsideBounds(int x, int y);

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