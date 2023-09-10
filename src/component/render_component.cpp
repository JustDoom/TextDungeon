//
// Created by dino on 6/09/23.
//

#include "render_component.h"
#include "ncurses.h"

RenderComponent::RenderComponent(char ch) {
    this->ch = ch;
    this->colour = 1;
}

RenderComponent::RenderComponent(char ch, int colour) {
    this->ch = ch;
    this->colour = colour;
}

void RenderComponent::update() {
    attron(COLOR_PAIR(colour + 1) | A_BOLD);
    printw("%c ", this->ch);
    attroff(COLOR_PAIR(colour + 1) | A_BOLD);
}

void RenderComponent::setChar(char ch) {
    this->ch = ch;
}

char RenderComponent::getChar() {
    return this->ch;
}

void RenderComponent::setColour(int colour) {
    this->colour = colour;
}

int RenderComponent::getColour() {
    return this->colour;
}