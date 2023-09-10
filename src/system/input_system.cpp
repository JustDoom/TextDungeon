//
// Created by dino on 8/09/23.
//

#include "input_system.h"
#include "ncurses.h"

InputSystem::InputSystem() {
    // Setup ncurses
    initscr();
    noecho();
    timeout(0);
    keypad(stdscr, TRUE);
    scrollok(stdscr, TRUE);

    // Colours
    start_color();
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
}

InputSystem::~InputSystem() {
    endwin();
}

void InputSystem::update(vector<Entity> &entities) {
    int ch = getch();
    if (ch != ERR) {
        for (auto& entity : entities) {
//            if (auto comp = entity.getComponent<PositionComponent>()) {
//                //entity.update();
//                comp->update();
//            }
        }

        //room->input(ch, this);
    }
}