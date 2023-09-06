//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_ROOM_SWITCH_H
#define TEXTDUNGEON_ROOM_SWITCH_H

#include "entity.h"
#include "../room/room.h"

class RoomSwitch : public Entity {
private:
    Room* connectedRoom;
    RoomSwitch* partner;

public:
    RoomSwitch(int priority, char ch, int colour, Room* connected, int x, int y);

    Room* getConnectedRoom();
    void setPartner(RoomSwitch* partner);
    RoomSwitch* getPartner();
};


#endif //TEXTDUNGEON_ROOM_SWITCH_H
