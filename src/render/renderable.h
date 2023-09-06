//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_RENDERABLE_H
#define TEXTDUNGEON_RENDERABLE_H


class Renderable {
private:
    char ch;
    int colour;
    int priority;

public:
    Renderable(int priority, char ch);
    Renderable(int priority, char ch, int colour);

    void render();

    void setChar(char ch);
    char getChar();
    void setColour(int colour);
    int getColour();
    void setPriority(int priority);
    int getPriority();
};


#endif //TEXTDUNGEON_RENDERABLE_H
