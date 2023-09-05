//
// Created by dino on 5/09/23.
//

#include "player.h"
#include "ncurses.h"

Player::Player(int x, int y) : Entity(x, y) {

}

void Player::handleMovement(int input) {
    if (input == 'w' || input == KEY_UP) {
        if (isOutsideBounds(x, y - 1)) {
            return this;
        }
        y--;
        changed = true;
    } else if (input == 'a' || input == KEY_LEFT) {
        if (isOutsideBounds(x - 1, y)) {
            return this;
        }
        x--;
        changed = true;
    } else if (input == 's' || input == KEY_DOWN) {
        if (isOutsideBounds(x, y + 1)) {
            return this;
        }
        y++;
        changed = true;
    } else if (input == 'd' || input == KEY_RIGHT) {
        if (isOutsideBounds(x + 1, y)) {
            return this;
        }
        x++;
        changed = true;
    }
    return this;
}