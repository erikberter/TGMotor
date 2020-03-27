//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_GAME_H
#define TEMPGAMEMOTOR_GAME_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_Image.h"
#include "ECS/ECS.h"
#include "ECS/entity_manager.h"
#include "ECS/asset_manager.h"


const int WIDTH = 800, HEIGH = 600;

class CollisionComponent;



class Game{
private:
    SDL_Window* win;

    bool is_running;
    int count;

    int frame_count, timer_fps,last_frame;
public:
    Game();
    ~Game();

    void main_loop();

    void input();
    void update();
    void render();

    SDL_Renderer *ren;
    static SDL_Event event;
    std::vector<CollisionComponent*> colliders;

    AssetManager ast_man;
    EntityManager e_man;

};

#endif //TEMPGAMEMOTOR_GAME_H
