//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_ENTITY_MANAGER_H
#define TEMPGAMEMOTOR_ENTITY_MANAGER_H


#include "ECS.h"
#include "physics/collision.h"

enum group_labels : std::size_t {
    G_PLAYER,G_ENEMY, G_COLLIDER, G_TILES
};

class EntityManager {
private:
     std::vector<std::size_t> loading_order;
public:
    Manager man;

    EntityManager();

    Entity& get_player(){return *man.get_group(G_PLAYER).back();};

    void draw();
    void update();

    std::vector<Entity*>& get_entities(std::size_t identifier){return man.get_group(identifier);};

    void set_place(int x, int y);


};


#endif //TEMPGAMEMOTOR_ENTITY_MANAGER_H
