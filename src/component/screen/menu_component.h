//
// Created by dino on 6/09/23.
//

#ifndef TEXTDUNGEON_RENDER_COMPONENT_H
#define TEXTDUNGEON_RENDER_COMPONENT_H

#include "../component.h"
#include "vector"

using namespace std;

class Component;

class MenuComponent : public Component {
private:
    vector<Entity*> entities;

public:
    MenuComponent();
//    MenuComponent(vector<Entity*> entities);

//    void update() override;

    void addEntity(Entity* entity);
    void removeEntity(Entity* entity);
    vector<Entity*> getEntities();
};


#endif //TEXTDUNGEON_RENDER_COMPONENT_H
