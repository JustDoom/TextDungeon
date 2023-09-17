//
// Created by doom on 5/09/23.
//

#ifndef TEXTDUNGEON_GAME_H
#define TEXTDUNGEON_GAME_H

#include "map"
#include "string"
#include "entity/entity.h"
#include "component/room_component.h"
#include "system/system.h"

using namespace std;

class Player;

class Game {
private:
    bool running;
    std::vector<System> systems;

public:
    Game();

    Player* player;

    void start();
    void stop();

    void setRunning(bool running);
    bool isRunning();
};


#endif //TEXTDUNGEON_GAME_H
