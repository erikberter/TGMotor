//
// Created by whiwho on 16/03/2020.
//

#ifndef TEMPGAMEMOTOR_TILE_COMPONENT_H
#define TEMPGAMEMOTOR_TILE_COMPONENT_H

#include "../ECS.h"
#include "components.h"

class Tile_component : public Component {
private:
    Transform_component *transf;
    Sprite_component *sprite;

    SDL_Rect tile_rect;
    int tile_id;
    char* path;
public:
    Tile_component() = default;

    Tile_component(int x, int y, int w, int h, int id){
        tile_rect.x = x;
        tile_rect.y = y;
        tile_rect.w = w;
        tile_rect.h = h;
        tile_id = id;
        switch(id){
            case 0:
                path = "../res/tiles/water-tile.png";
                break;
            case 1:
                path = "../res/tiles/grass-tile.png";
                break;
            default:
                break;
        }
    }

    void init() override{
        entity->add_component<Transform_component>(tile_rect.x,tile_rect.y,tile_rect.h,tile_rect.w,1);
        transf =  &entity->get_component<Transform_component>();

        entity->add_component<Sprite_component>(path, false);
        sprite = &entity->get_component<Sprite_component>();
    }
};

#endif //TEMPGAMEMOTOR_TILE_COMPONENT_H