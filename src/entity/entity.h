//
// Created by dino on 5/09/23.
//

#ifndef TEXTDUNGEON_ENTITY_H
#define TEXTDUNGEON_ENTITY_H

#include "../component/component.h"
#include "vector"
#include "memory"

using namespace std;

class Component;

class Entity {
private:
    vector<std::shared_ptr<Component>> components;

public:
    void addComponent(std::shared_ptr<Component> component);
    template <typename T>
    shared_ptr<T> getComponent() {
        for (auto& component : this->components) {
            if (auto casted = std::dynamic_pointer_cast<T>(component)) {
                return casted;
            }
        }
        return nullptr;
    }

    void update(); // Might all be handled by systems
};

#endif //TEXTDUNGEON_ENTITY_H
