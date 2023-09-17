//
// Created by dino on 12/09/23.
//

#ifndef TEXTDUNGEON_ROOM_MANAGER_H
#define TEXTDUNGEON_ROOM_MANAGER_H

#include "../component/room_component.h"
#include "string"
#include "unordered_map"
#include "../entity/entity.h"

class RoomManager {
private:
    Entity* currentRoom;
    std::unordered_map<std::string, Entity*> rooms; // TODO: Does this need to be a map?
public:
    RoomManager() = default;

    void update();

    void addRoom(std::string name, Entity* room);
    std::unordered_map<std::string, Entity*> getRooms();

    void setCurrentRoom(Entity* currentRoom);
    Entity* getCurrentRoom();
};


#endif //TEXTDUNGEON_ROOM_MANAGER_H
