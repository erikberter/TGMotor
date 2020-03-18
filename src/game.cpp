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
Entity_manager Game::e_man;
Asset_manager Game::ast_man;
Manager map_manager;




Game::Game(){
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGH, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Eralia");
    Game::ast_man.load_default();

    map = Game_map("map_prueba.map");

    is_running = true;
    count = 0;

    enemy::add_player();
    player::add_player();
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

        input();
        update();
        render();

        frame_count++;
        int timer_fps = SDL_GetTicks()-last_frame;
        // 17 = ceil( 1 s / 60 fps )
        if(timer_fps < 17)
            SDL_Delay(17-timer_fps);
    }
}


void Game::render() {

    SDL_RenderClear(ren);
    map_manager.draw();
    Game::e_man.draw();
    SDL_RenderPresent(ren);

}

void Game::update(){
    Game::e_man.update();

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