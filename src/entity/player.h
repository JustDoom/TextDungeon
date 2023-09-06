//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_PLAYER_H
#define TEXTDUNGEON_PLAYER_H

#include "entity.h"
#include "../room/room.h"
#include "../listener/input_listener.h"

class Room;

class Player : public InputListener, public Entity {
private:
public:
    Player(char ch, int x, int y);

    void handleMovement(int input, Room* room);

    void input(int ch) override;
};

#endif //TEXTDUNGEON_PLAYER_H
