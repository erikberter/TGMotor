#include "ECS/entity_manager.h"
#include "ECS/Components/sprite_component.h"

EntityManager::EntityManager(){
    loading_order = {G_PLAYER, G_ENEMY, G_TILES};
}

void EntityManager::draw_in_order(){
    for(std::size_t order_t : loading_order)
        for(auto& t : get_group(order_t))
            t->draw();
}

void EntityManager::set_displacement(int x, int y){
    for(std::size_t order_t : loading_order)
        for(auto& t : get_group(order_t))
            dynamic_cast<SpriteComponent*>(t->get_component(ComponentHelper::SPRITE))->set_place(x,y);
}