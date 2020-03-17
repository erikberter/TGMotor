//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_PLAYER_H
#define TEMPGAMEMOTOR_PLAYER_H

#include "../game.h"
#include "../ECS/Components/components.h"

class player{
public:

    static void add_player() {
        auto& player(Game::man.add_entity());
        player.add_component<Transform_component>();
        player.add_component<Sprite_component>("../res/sprite/mago1.png", true);
        player.add_component<Keyboard_controller>();
        player.add_component<Collision_component>("Player");

        player.add_group(G_PLAYER);
    }

};

#endif //TEMPGAMEMOTOR_PLAYER_H
