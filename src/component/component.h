//
// Created by dino on 8/09/23.
//

#ifndef TEXTDUNGEON_COMPONENT_H
#define TEXTDUNGEON_COMPONENT_H

#include "../entity/entity.h"

class Entity;

class Component {
public:
    Component();
    Component(Entity* entity);
    virtual ~Component() = default;

    Entity* owner;

    virtual void initialize() {};
    virtual void update() {};
};

#endif //TEXTDUNGEON_COMPONENT_H
