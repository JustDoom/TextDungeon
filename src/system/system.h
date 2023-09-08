//
// Created by dino on 8/09/23.
//

#ifndef TEXTDUNGEON_SYSTEM_H
#define TEXTDUNGEON_SYSTEM_H

#include "../entity/entity.h"
#include "vector"

using namespace std;

class System {
public:
    virtual void update(vector<Entity>& entities) {};
};

#endif //TEXTDUNGEON_SYSTEM_H
