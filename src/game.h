//
// Created by doom on 5/09/23.
//

#ifndef TEXTDUNGEON_GAME_H
#define TEXTDUNGEON_GAME_H

#include "room/room.h"
#include "vector"
#include "string"

using namespace std;

class Room;
class Player;

class Game {
private:
    bool running;
    Room* room;
    map<string, Room> rooms;

public:
    Game();

    Player* player;

    void start();
    void stop();

    void setRunning(bool running);
    bool isRunning();

    void setCurrentRoom(Room* room);
    Room* getCurrentRoom();
};


#endif //TEXTDUNGEON_GAME_H
