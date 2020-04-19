//
// Created by whiwho on 07/04/2020.
//

#ifndef GAME_MOTOR_TILE_ENTITY_H
#define GAME_MOTOR_TILE_ENTITY_H

#include "ECS/Components/sprite_component.h"
#include "ECS/Components/transform_component.h"

const std::string tile_names[2] = {
        "../res/assets/tiles/tile-building.png",
        "../res/assets/tiles/tile-floor.png"
};

/**
 * A tile Object is just a square to be placed at the screen.
 */
class tile_entity{
public:
    static void add_tile(std::string id, Game* gApp, int tile_type, int y, int x) {
        auto& player = gApp->e_man.man.add_entity();
        player.add_component<TransformComponent>(x*50,y*50, 50,50,1);
        player.add_component<SpriteComponent>(tile_names[tile_type].c_str(),  gApp);
        player.add_group(G_TILES);
    }

};

#endif //GAME_MOTOR_TILE_ENTITY_H
