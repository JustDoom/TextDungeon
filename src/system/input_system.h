//
// Created by dino on 8/09/23.
//

#ifndef TEXTDUNGEON_INPUT_SYSTEM_H
#define TEXTDUNGEON_INPUT_SYSTEM_H

#include "vector"
#include "../entity/entity.h"
#include "system.h"

using namespace std;

class InputSystem : public System {
private:
public:
    InputSystem();
    ~InputSystem();

    void update(vector<Entity>& entities) override;
};


#endif //TEXTDUNGEON_INPUT_SYSTEM_H
