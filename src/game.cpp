//
// Created by doom on 5/09/23.
//

#include "game.h"
#include "room/room.h"
#include "ncurses.h"
#include "memory"
#include "listener/input_listener.h"
#include "iostream"

using namespace std;

Game::Game() {
    this->rooms = {};
}

void Game::start() {
    running = true;

    vector<InputListener*> inputListeners;
    Player player('X', 1, 1);
    this->player = &player;
    inputListeners.push_back(&player);

    // Add all the rooms
    rooms["test"] = Room(5, 5);
    rooms["test2"] = Room(2, 5);
    rooms["test3"] = Room(10, 20);

    // Add room to listener
    inputListeners.push_back(&rooms["test"]);
    inputListeners.push_back(&rooms["test2"]);
    inputListeners.push_back(&rooms["test3"]);

    // Add rooms to rooms
    rooms["test"].addRoom(&rooms["test2"], 3, 3);
    rooms["test"].addRoom(&rooms["test3"], 4, 3);
    rooms["test2"].addRoom(&rooms["test"], 2, 2);

    // Setup current room
    room = &rooms["test"];
    rooms["test"].addEntity(&player);

    initscr();
    start_color();

    // Colours
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);

    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    // Main loop
    while (running) {
        room->render();

        int ch = getch();
        if (ch != ERR) {
            room->move();
            for (InputListener* listener : inputListeners) {
                if (auto* v = dynamic_cast<Player*>(listener)) {
                    v->handleMovement(ch, room);
                }
//                else if (auto* e = dynamic_cast<Room*>(listener)) {
//                    e->input(ch, this);
//                }
            }

            room->input(ch, this);
        }

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