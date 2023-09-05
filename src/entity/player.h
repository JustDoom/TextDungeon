//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_PLAYER_H
#define TEXTDUNGEON_PLAYER_H

#include "entity.h"

class Player : public Entity {
private:
public:
    Player(int x, int y);

    void handleMovement(int input);
};

#endif //TEXTDUNGEON_PLAYER_H
