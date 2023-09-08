//
// Created by dino on 8/09/23.
//

#include "input_system.h"
#include "ncurses.h"
#include "../component/position_component.h"

InputSystem::InputSystem() {

}

InputSystem::~InputSystem() {
    endwin();
}

void InputSystem::update(vector<Entity> &entities) {
    int ch = getch();
    if (ch != ERR) {
        for (auto& entity : entities) {
            if (auto comp = entity.getComponent<PositionComponent>()) {
                //entity.update();
                comp->update();
            }
        }

        //room->input(ch, this);
    }
}