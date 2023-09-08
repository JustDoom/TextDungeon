//
// Created by doom on 5/09/23.
//

#include "game.h"
#include "room/room.h"
#include "ncurses.h"
#include "memory"
#include "listener/input_listener.h"

using namespace std;

Game::Game() {
    this->rooms = {};
}

void Game::start() {
    running = true;

//    Player player(1, 'X', COLOR_GREEN, 1, 1);
//    this->player = &player;
//    inputListeners.push_back(&player);

    // Add all the rooms
    rooms["test"] = Room(5, 5);
    rooms["test2"] = Room(2, 5);
    rooms["test3"] = Room(10, 20);

    // Create room switch entities
//    RoomSwitch roomSwitch = RoomSwitch(2, 'R', COLOR_BLUE, &rooms["test2"], 3, 3);
//    RoomSwitch roomSwitch2 = RoomSwitch(2, 'R', COLOR_BLUE, &rooms["test"], 2, 2);
//    RoomSwitch roomSwitch3 = RoomSwitch(2, 'R', COLOR_BLUE, &rooms["test3"], 5, 2);
//    RoomSwitch roomSwitch4 = RoomSwitch(2, 'R', COLOR_BLUE, &rooms["test2"], 2, 7);
//
//    roomSwitch.setPartner(&roomSwitch2);
//    roomSwitch2.setPartner(&roomSwitch);
//    roomSwitch3.setPartner(&roomSwitch4);
//    roomSwitch4.setPartner(&roomSwitch3);
//
//    // Add rooms to rooms
//    rooms["test"].addEntity(&roomSwitch);
//    rooms["test2"].addEntity(&roomSwitch2);
//    rooms["test2"].addEntity(&roomSwitch3);
//    rooms["test3"].addEntity(&roomSwitch4);


    // Setup current room
    room = &rooms["test"];

    // Setup ncurses
    initscr();
    start_color();

    // Colours
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);

    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    // Main loop
    while (running) {
        room->render();

//        int ch = getch();
//        if (ch != ERR) {
//            room->move();
//            for (InputListener* listener : inputListeners) {
//                if (auto* v = dynamic_cast<Player*>(listener)) {
//                    v->handleMovement(ch, room);
//                }
////                else if (auto* e = dynamic_cast<Room*>(listener)) {
////                    e->input(ch, this);
////                }
//            }
//
//            room->input(ch, this);
//        }

        usleep(10000); // Prevent insane CPU usage
    }
}

void Game::stop() {
    running = false;
}

void Game::setRunning(bool running) {
    running = running;
}

bool Game::isRunning() {
    return running;
}

void Game::setCurrentRoom(Room *room) {
    this->room = room;
    room->changed = true;
}

Room* Game::getCurrentRoom() {
    return room;
}