//
// Created by whiwho on 16/03/2020.
//

#ifndef TEMPGAMEMOTOR_TILE_COMPONENT_H
#define TEMPGAMEMOTOR_TILE_COMPONENT_H

#include "ECS/ECS.h"
#include "components.h"

const std::string tile_tex_list[2] = {
        "../res/tiles/water-tile.png",
        "../res/tiles/grass-tile.png"
};

class TileComponent : public Component {
private:
    TransformComponent *transf;
    SpriteComponent *sprite;

    SDL_Rect tile_rect;
    int tile_id;
    const char* path;
public:
    TileComponent() = default;

    TileComponent(int x, int y, int w, int h, int id){
        tile_rect.x = x;
        tile_rect.y = y;
        tile_rect.w = w;
        tile_rect.h = h;
        tile_id = id;
        // TODO Abstract the way of getting tile tex
        // TODO Check if valid id
        path = tile_tex_list[id].c_str();
    }

    void init() override{
        entity->add_component<TransformComponent>(tile_rect.x,tile_rect.y,tile_rect.h,tile_rect.w,1);
        transf =  &entity->get_component<TransformComponent>();

        entity->add_component<SpriteComponent>(path);
        sprite = &entity->get_component<SpriteComponent>();
    }
};

#endif //TEMPGAMEMOTOR_TILE_COMPONENT_H
