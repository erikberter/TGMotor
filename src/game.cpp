//
// Created by whiwho on 14/03/2020.
//

#include "game.h"
#include "game_map.h"
#include "ECS/ECS.h"
#include "ECS/Components/components.h"
#include "ECS/Components/tile_component.h"

#include "entities/player.h"
#include "entities/enemy.h"

SDL_Renderer* Game::ren = nullptr;
SDL_Event Game::event;

std::vector<Collision_component*> Game::colliders;

Game_map map;
Manager Game::man;
Manager map_manager;




Game::Game(){
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGH, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Eralia");

    map = Game_map("map_prueba.map");

    is_running = true;
    count = 0;

    player::add_player();
    enemy::add_player();
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

auto& players(Game::man.get_group(G_PLAYER));
auto& enemies(Game::man.get_group(G_ENEMY));
void Game::render() {

    SDL_RenderClear(ren);
    map_manager.draw();
    for(auto& t : players)
        t->draw();
    for(auto& t : enemies)
        t->draw();
    SDL_RenderPresent(ren);

}

void Game::update(){
    Game::man.refresh();
    Game::man.update();

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

void Game::add_tile(int x, int y, int id){
    auto& tile(map_manager.add_entity());
    tile.add_component<Tile_component>(x,y,32,32, id);
}