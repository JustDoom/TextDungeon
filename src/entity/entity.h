//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_ENTITY_H
#define TEXTDUNGEON_ENTITY_H

#include "../component/component.h"
#include "vector"
#include "memory"

using namespace std;

class Entity {
private:
    vector<shared_ptr<Component>> components;

public:
    void addComponent(shared_ptr<Component> component);
    template <typename T> shared_ptr<T> getComponent();

    void update(); // Might all be handled by systems
};


#endif //TEXTDUNGEON_ENTITY_H
