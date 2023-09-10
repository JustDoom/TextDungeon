//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_RENDER_COMPONENT_H
#define TEXTDUNGEON_RENDER_COMPONENT_H

#include "component.h"

class RenderComponent : public Component {
private:
    char ch;
    int colour;

public:
    RenderComponent(char ch);
    RenderComponent(char ch, int colour);

    void update() override;

    void setChar(char ch);
    char getChar();
    void setColour(int colour);
    int getColour();
};


#endif //TEXTDUNGEON_RENDER_COMPONENT_H
