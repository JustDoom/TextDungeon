//
// Created by doom on 5/09/23.
//

#include "game.h"
#include <thread>
#include <chrono>

using namespace std;

Game::Game() {
    this->rooms = {};
    this->running = false;

    // TODO: Do map loading stuff etc properly from file

    Entity roomEntity;
    roomEntity.addComponent(RoomComponent());
}

void Game::start() {
    this->running = true;

    while (this->running) {
        for ()

        this_thread::sleep_for(chrono::milliseconds(10));
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

void Game::setCurrentRoom(RoomComponent &currentRoom) {
    this->currentRoom = currentRoom;
}

RoomComponent &Game::getCurrentRoom() {
    return this->currentRoom;
}
