//
// Created by doom on 5/09/23.
//

#include "game.h"
#include <thread>
#include <chrono>
#include "manager/room_manager.h"
#include "component/room_component.h"
#include "component/position_component.h"
#include "component/render_component.h"
#include "memory"
#include "entity/entity.h"

using namespace std;

#include "iostream"
#include "ncurses.h"

class Entity;
class RoomComponent;

Game::Game() {
    this->running = false;

    // TODO: Do map loading stuff etc properly from file
}

void Game::start() {
    this->running = true;
    RoomManager roomManager;

    Entity roomEntity;
    roomEntity.addComponent(std::make_shared<RoomComponent>(5, 5));

    Entity playerEntity;
    playerEntity.addComponent(std::make_shared<PositionComponent>(1, 1));
    playerEntity.addComponent(std::make_shared<RenderComponent>('P', 3));

    roomEntity.getComponent<RoomComponent>()->addEntity(&playerEntity);

    roomManager.addRoom("test", &roomEntity);

    roomManager.setCurrentRoom(roomManager.getRooms().at("test"));

    initscr();
    start_color();

    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    while (this->running) {
        clear();
//        for (System system : systems) {
//
//        }
        for (pair<std::string, Entity*> room : roomManager.getRooms()) {
            for (Entity* entity : room.second->getComponent<RoomComponent>()->getEntities()) {
                if (auto render = entity->getComponent<RenderComponent>()) {
                    render->update();
                    printw("EEEE");
//                    std::cout << "e" << std::endl;
                }
            }
        }

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