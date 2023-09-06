//
// Created by dino on 5/09/23.
//

#include "player.h"
#include "ncurses.h"

Player::Player(char ch, int x, int y) : Entity(ch, x, y) {}

void Player::handleMovement(int input, Room* room) {
    if (input == 'w' || input == KEY_UP) {
        if (room->isOutsideBounds(getX(), getY() - 1)) {
            return;
        }
        setY(getY() - 1);
        room->changed = true;
    } else if (input == 'a' || input == KEY_LEFT) {
        if (room->isOutsideBounds(getX() - 1, getY())) {
            return;
        }
        setX(getX() - 1);;
        room->changed = true;
    } else if (input == 's' || input == KEY_DOWN) {
        if (room->isOutsideBounds(getX(), getY() + 1)) {
            return;
        }
        setY(getY() + 1);
        room->changed = true;
    } else if (input == 'd' || input == KEY_RIGHT) {
        if (room->isOutsideBounds(getX() + 1, getY())) {
            return;
        }
        setX(getX() + 1);
        room->changed = true;
    }
}

void Player::input(int ch) {
    //handleMovement(ch, nullptr); // This is the current movement issue
    //exit(1);
}