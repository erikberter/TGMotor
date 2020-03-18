//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_ENEMY_H
#define TEMPGAMEMOTOR_ENEMY_H
#include "../game.h"
#include "../ECS/Components/components.h"
#include "../ECS/Components/random_movement_component.h"

class enemy{
public:
    static int enemy_id;
    static void add_player(std::string id) {
        auto& player(Game::e_man.man.add_entity());
        player.add_component<Transform_component>();
        player.add_component<Random_component>();
        player.add_component<Sprite_component>(id, true);
        player.add_component<Collision_component>("Enemy" +std::to_string(enemy_id++));

        player.add_group(G_ENEMY);
    }

};


#endif //TEMPGAMEMOTOR_ENEMY_H
