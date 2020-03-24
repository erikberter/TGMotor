//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_ENEMY_H
#define TEMPGAMEMOTOR_ENEMY_H
#include "game.h"
#include "ECS/Components/components.h"
#include "ECS/Components/random_movement_component.h"

class enemy{
public:
    static int enemy_id;
    static void add_enemy(std::string sprite_name, Game* gApp) {
        auto& player(gApp->e_man.man.add_entity());
        player.add_component<TransformComponent>();
        player.add_component<RandomComponent>();
        player.add_component<SpriteComponent>(sprite_name, gApp,  true);
        player.add_component<CollisionComponent>();

        player.add_group(G_ENEMY);
    }

};


#endif //TEMPGAMEMOTOR_ENEMY_H
