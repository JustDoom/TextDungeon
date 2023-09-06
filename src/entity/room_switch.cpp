//
// Created by dino on 6/09/23.
//

#include "room_switch.h"
#include "entity.h"

RoomSwitch::RoomSwitch(char ch, int colour, Room* connected, int x, int y) : Entity(ch, colour, x, y) {
    this->connectedRoom = connected;
}

Room* RoomSwitch::getConnectedRoom() {
    return connectedRoom;
}

void RoomSwitch::setPartner(RoomSwitch* partner) {
    this->partner = partner;
}

RoomSwitch* RoomSwitch::getPartner() {
    return this->partner;
}