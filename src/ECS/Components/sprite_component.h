//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_SPRITE_COMPONENT_H
#define TEMPGAMEMOTOR_SPRITE_COMPONENT_H

#include "transform_component.h"
#include "SDL.h"
#include "../../texture_manager.h"

class Sprite_component : public Component{
private:
    Transform_component *transf;
    SDL_Texture *tex;
    SDL_Rect src,dest;

public:

    Sprite_component() = default;
    Sprite_component(const char* file_path){
        set_tex(file_path);
    }

    ~Sprite_component(){
        SDL_DestroyTexture(tex);
    }

    void set_tex(const char* file_path){
        tex = TextureManager::LoadTexture(file_path);
    }

    void init() override{
        if(!entity->has_component<Transform_component>())
            entity->add_component<Transform_component>();
        transf = &entity->get_component<Transform_component>();

        src.x = src.y = 0;
        src.w = transf->width;
        src.h = transf->height;

        dest.x = static_cast<int>(transf->x());
        dest.y = static_cast<int>(transf->y());
        dest.w = dest.h = 64;
        std::cout  << "Estamos en " << dest.x << " : " << dest.y << std::endl;
    }

#include <iostream>
    void update() override{
        dest.x = static_cast<int>(transf->x());
        dest.y = static_cast<int>(transf->y());

        dest.w = static_cast<int>(transf->width*transf->scale);
        dest.h = static_cast<int>(transf->height*transf->scale);
    }

    void draw() override{
        TextureManager::draw(tex, src,dest);
    }
};

#endif //TEMPGAMEMOTOR_SPRITE_COMPONENT_H
