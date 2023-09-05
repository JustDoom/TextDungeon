//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_ENTITY_H
#define TEXTDUNGEON_ENTITY_H

class Entity {
private:
    int x;
    int y;

public:
    Entity(int x, int y);

    void setX(int x);
    int getX();
    void setY(int y);
    int getY();
};


#endif //TEXTDUNGEON_ENTITY_H
