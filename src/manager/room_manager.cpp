//
// Created by dino on 12/09/23.
//

#include "room_manager.h"

void RoomManager::update() {

}

void RoomManager::addRoom(std::string name, Entity *room) {
    this->rooms[name] = room;
}

unordered_map<std::string, Entity*> RoomManager::getRooms() {
    return this->rooms;
}

void RoomManager::setCurrentRoom(Entity* currentRoom) {
    this->currentRoom = currentRoom;
}

Entity* RoomManager::getCurrentRoom() {
    return this->currentRoom;
}
