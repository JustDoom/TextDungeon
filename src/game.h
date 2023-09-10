//
// Created by doom on 5/09/23.
//

#ifndef TEXTDUNGEON_GAME_H
#define TEXTDUNGEON_GAME_H

#include "map"
#include "string"
#include "entity/entity.h"
#include "component/room_component.h"

using namespace std;

class Room;
class Player;

class Game {
private:
    bool running;
    RoomComponent& currentRoom;
    map<string, Entity*> rooms; // TODO: Does this need to be a map?

public:
    Game();

    Player* player;

    void start();
    void stop();

    void setRunning(bool running);
    bool isRunning();

    void setCurrentRoom(RoomComponent& currentRoom);
    RoomComponent& getCurrentRoom();
};


#endif //TEXTDUNGEON_GAME_H
