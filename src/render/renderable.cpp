//
// Created by dino on 6/09/23.
//

#include "renderable.h"
#include "ncurses.h"

Renderable::Renderable(char ch) {
    this->ch = ch;
}

void Renderable::render() {
    attron(COLOR_PAIR(1) | A_BOLD);
    printw("%c ", this->ch);
    attroff(COLOR_PAIR(1) | A_BOLD);
}

void Renderable::setChar(char ch) {
    this->ch = ch;
}

char Renderable::getChar() {
    return this->ch;
}