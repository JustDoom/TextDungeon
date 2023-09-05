//
// Created by doom on 5/09/23.
//

#include "game.h"
#include "room.h"
#include "ncurses.h"
#include "memory"
#include "listener/input_listener.h"

Game::Game() {
    this->rooms = {};
}

void Game::start() {
    running = true;

    vector<InputListener*> inputListeners;
    Player player(1, 1);
    this->player = &player;
    inputListeners.push_back(&player);

    // Add all the rooms
    rooms.emplace_back(5, 5);
    room = &rooms[0];
    rooms.emplace_back(2, 4);
    rooms.emplace_back(10, 20);

    // Add room to listener
    inputListeners.push_back(&rooms[0]);
    inputListeners.push_back(&rooms[1]);
    inputListeners.push_back(&rooms[2]);

    // Add rooms to rooms
    rooms[0].addRoom(&rooms[1], 3, 3);
    rooms[0].addRoom(&rooms[2], 4, 3);
    rooms[1].addRoom(&rooms[0], 2, 2);

    rooms[0].addEntity(player);

    initscr();
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
                listener->input(ch);
            }
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
}

Room* Game::getCurrentRoom() {
    return room;
}