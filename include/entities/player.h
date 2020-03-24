//
// Created by whiwho on 17/03/2020.
//

#ifndef TEMPGAMEMOTOR_PLAYER_H
#define TEMPGAMEMOTOR_PLAYER_H

#include "game.h"
#include "ECS/Components/components.h"

class player{
public:

    static void add_player(std::string sprite_name, Game* gApp) {
        auto& player(gApp->e_man.man.add_entity());
        player.add_component<TransformComponent>();
        player.add_component<SpriteComponent>(sprite_name, gApp, true);
        player.add_component<KeyboardController>();
        player.add_component<CollisionComponent>();

        player.add_group(G_PLAYER);
    }

};

#endif //TEMPGAMEMOTOR_PLAYER_H
