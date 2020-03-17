//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_SPRITE_COMPONENT_H
#define TEMPGAMEMOTOR_SPRITE_COMPONENT_H

#include "transform_component.h"
#include "SDL.h"
#include "../../texture_manager.h"
#include "../animation.h"
#include <map>

class Sprite_component : public Component{
private:
    Transform_component *transf;
    SDL_Texture *tex;
    SDL_Rect src,dest;

    bool is_animated = false;

    int frames = 0;
    int speed = 100;

public:
    int animation_id = 0;

    std::map<const char*, Animation> animations;

    Sprite_component() = default;

    Sprite_component(const char* file_path, bool animated){
        is_animated = animated;

        if(is_animated){
            Animation stand = Animation(0, 1, 100);
            Animation walk_front = Animation(1, 4, 100);
            Animation walk_lateral = Animation(2, 4, 100);
            Animation walk_back = Animation(3, 4, 100);
            animations.emplace("stand",stand);
            animations.emplace("walk_front",walk_front);
            animations.emplace("walk_lateral",walk_lateral);
            animations.emplace("walk_back",walk_back);

            play("stand");
        }
        speed = 1;
        animation_id = 0;
        set_tex(file_path);
    }

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

        transf->scale = 2;

        src.x = src.y = 0;
        src.w = transf->width;
        src.h = transf->height;

        dest.x = static_cast<int>(transf->x());
        dest.y = static_cast<int>(transf->y());
        dest.w = dest.h = 50;
    }

#include <iostream>
    void update() override{
        if(is_animated)
            src.x = src.w* static_cast<int>((SDL_GetTicks() / speed) % frames);

        src.y = animation_id * transf->height;
        dest.x = static_cast<int>(transf->x());
        dest.y = static_cast<int>(transf->y());

        dest.w = static_cast<int>(transf->width*transf->scale);
        dest.h = static_cast<int>(transf->height*transf->scale);
    }

    void draw() override{
        TextureManager::draw(tex, src,dest);
    }

    void play(const char* anim_name){
        frames = animations[anim_name].frames;
        animation_id = animations[anim_name].index;
        speed = animations[anim_name].speed;
    }
};

#endif //TEMPGAMEMOTOR_SPRITE_COMPONENT_H
