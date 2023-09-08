//
// Created by dino on 8/09/23.
//

#ifndef TEXTDUNGEON_POSITION_COMPONENT_H
#define TEXTDUNGEON_POSITION_COMPONENT_H

#include "component.h"

class PositionComponent : public Component {
private:
    int x;
    int y;
public:
    PositionComponent(int x, int y);
    void update() override;
};


#endif //TEXTDUNGEON_POSITION_COMPONENT_H
