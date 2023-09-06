//
// Created by dino on 6/09/23.
//

#include "renderable.h"
#include "ncurses.h"

Renderable::Renderable(int priority, char ch) {
    this->priority = priority;
    this->ch = ch;
}

Renderable::Renderable(int priority, char ch, int colour) {
    this->priority = priority;
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

void Renderable::setPriority(int priority) {
    this->priority = priority;
}

int Renderable::getPriority() {
    return this->priority;
}