//
// Created by whiwho on 17/03/2020.
//

#include "entity_manager.h"
#include "../entities/player.h"

#include "Components/collision_component.h"

Manager Entity_manager::man;

Entity_manager::Entity_manager(){
    loading_order.push_back(G_PLAYER);
    loading_order.push_back(G_ENEMY);

    player::add_player();


}

void Entity_manager::update(){
    Entity_manager::man.refresh();
    Entity_manager::man.update();
    for(auto& enem : man.get_group(G_ENEMY))
        if(Collision::is_collision(enem->get_component<Collision_component>().coll,get_player().get_component<Collision_component>().coll ))
            std::cout << " Han chocdo!!" << std::endl;
}