//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_ENTITY_H
#define TEXTDUNGEON_ENTITY_H

#include "../render/renderable.h"

class Entity : public Renderable {
private:
    int x;
    int y;
    char ch;

public:
    Entity(char ch, int colour, int x, int y);
    virtual ~Entity() = default;

    void setX(int x);
    int getX();
    void setY(int y);
    int getY();

};


#endif //TEXTDUNGEON_ENTITY_H
