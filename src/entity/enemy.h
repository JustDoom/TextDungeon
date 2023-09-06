//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_ENEMY_H
#define TEXTDUNGEON_ENEMY_H

#include "entity.h"

class Enemy : public Entity {
private:
public:
    Enemy(int priority, char ch, int colour, int x, int y);
};

#endif //TEXTDUNGEON_ENEMY_H
