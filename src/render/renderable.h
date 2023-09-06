//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_RENDERABLE_H
#define TEXTDUNGEON_RENDERABLE_H


class Renderable {
private:
    char ch;

public:
    Renderable(char ch);

    void render();

    void setChar(char ch);
    char getChar();
};


#endif //TEXTDUNGEON_RENDERABLE_H
