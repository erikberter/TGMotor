//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_KEYBOARD_CONTROLLER_H
#define TEMPGAMEMOTOR_KEYBOARD_CONTROLLER_H

#include "../game.h"
#include "ECS.h"
#include "Components/transform_component.h"

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
class Keyboard_controller : public Component {
public:
    Transform_component *transf;
    Sprite_component *sprite;
    Keyboard_controller(){
    };

    void init() override{
        if(!entity->has_component<Transform_component>())
            entity->add_component<Transform_component>();
        transf = &entity->get_component<Transform_component>();
        if(!entity->has_component<Sprite_component>())
            entity->add_component<Sprite_component>();
        sprite = &entity->get_component<Sprite_component>();
    }

    void update() override{
        if(Game::event.type == SDL_KEYDOWN){
            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    transf->vel.y = -1;
                    sprite->play("walk_back");
                    break;
                case SDLK_s:
                    transf->vel.y = 1;
                    sprite->play("walk_front");
                    break;
                case SDLK_a:
                    transf->vel.x = -1;
                    sprite->play("walk_lateral");
                    break;
                case SDLK_d:
                    transf->vel.x = 1;
                    sprite->play("walk_lateral");
                    break;
                case SDLK_SPACE:

                default:
                    break;
            }
        }

        if(Game::event.type == SDL_KEYUP){
            switch(Game::event.key.keysym.sym){
                case SDLK_w:
                    transf->vel.y = 0;
                    sprite->play("stand");
                    break;
                case SDLK_s:
                    transf->vel.y = 0;
                    sprite->play("stand");
                    break;
                case SDLK_a:
                    transf->vel.x = 0;
                    sprite->play("stand");
                    break;
                case SDLK_d:
                    transf->vel.x = 0;
                    sprite->play("stand");
                    break;
                default:
                    break;
            }
        }

    }

};


#endif //TEMPGAMEMOTOR_KEYBOARD_CONTROLLER_H
