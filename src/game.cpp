//
// Created by whiwho on 14/03/2020.
//

#include "game.h"
#include "game_map.h"
#include "ECS/ECS.h"
#include "ECS/Components/components.h"
#include "physics/collision.h"

SDL_Renderer* Game::ren = nullptr;
SDL_Event Game::event;


Game_map map;
Manager man;

auto& player(man.add_entity());
auto& wall(man.add_entity());

Game::Game(){
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGH, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Eralia");

    map = Game_map("map_prueba.map");

    is_running = true;
    count = 0;

    player.add_component<Transform_component>();
    player.add_component<Keyboard_controller>();
    player.add_component<Collision_component>("Player");
    player.add_component<Sprite_component>("../res/sprite/sp1.png");

    wall.add_component<Transform_component>(320,320,32,32,1);
    wall.add_component<Sprite_component>("../res/sprite/star.png");
    wall.add_component<Collision_component>("Wall");
}
Game::~Game(){
    is_running = false;
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}

void Game::main_loop() {



    static int last_time=0;
    while(is_running){

        last_frame = SDL_GetTicks();

        if(last_frame >= last_time+1000){
            last_time = last_frame;
            frame_count=0;
            count++;
        }

        input();
        update();
        render();

        frame_count++;
        int timer_fps = SDL_GetTicks()-last_frame;
        // 17 = ceil( 1 s / 60 fps )
        if(timer_fps < 17)
            SDL_Delay(17-timer_fps);

        if(count>300) is_running=false;
    }
}

void Game::render() {

    SDL_RenderClear(ren);
    map.render_map();
    man.draw();
    SDL_RenderPresent(ren);

}

void Game::update(){
    man.refresh();
    man.update();
    if(Collision::is_collision(
            player.get_component<Collision_component>().coll,
            wall.get_component<Collision_component>().coll)
            ){
        player.get_component<Transform_component>().vel*=-1;
        player.update();
        player.get_component<Transform_component>().vel*=-1;
    }
}

void Game::input(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
    }
}
