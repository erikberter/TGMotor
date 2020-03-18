//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_ENTITY_MANAGER_H
#define TEMPGAMEMOTOR_ENTITY_MANAGER_H


#include "ECS.h"
#include "../physics/collision.h"

enum group_labels : std::size_t {
    G_PLAYER,G_ENEMY, G_COLLIDER
};

class Entity_manager {
private:
     std::vector<std::size_t> loading_order;
public:
    static Manager man;

    Entity_manager();

    Entity& get_player(){return *Entity_manager::man.get_group(G_PLAYER).back();};

    void draw(){
        for(std::size_t order_t : loading_order)
            for(auto& t : Entity_manager::man.get_group(order_t))
                t->draw();
    }
    void update();

    std::vector<Entity*>& get_entities(std::size_t identifier){return man.get_group(identifier);};



};


#endif //TEMPGAMEMOTOR_ENTITY_MANAGER_H
