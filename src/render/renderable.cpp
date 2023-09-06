//
// Created by dino on 6/09/23.
//

#include "renderable.h"
#include "ncurses.h"

Renderable::Renderable(char ch) {
    this->ch = ch;
}

Renderable::Renderable(char ch, int colour) {
    this->colour = colour;
    this->ch = ch;
}

void Renderable::render() {
    attron(COLOR_PAIR(colour + 1) | A_BOLD);
    printw("%c ", this->ch);
    attroff(COLOR_PAIR(colour + 1) | A_BOLD);
}

void Renderable::setChar(char ch) {
    this->ch = ch;
}

char Renderable::getChar() {
    return this->ch;
}

void Renderable::setColour(int colour) {
    this->colour = colour;
}

int Renderable::getColour() {
    return this->colour;
}