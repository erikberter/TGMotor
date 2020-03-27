//
// Created by whiwho on 14/03/2020.
//

#include <texture_manager.h>
#include "game.h"
#include "game_map.h"
#include "ECS/ECS.h"


SDL_Event Game::event;

GameMap map;
Manager map_manager;


Game::Game(){
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGH, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Eralia");
    std::cout << "H5" << std::endl;
    ast_man.load_default(ren);
    std::cout << "H6" << std::endl;
    map = GameMap("map_prueba", this);
    std::cout << "H7" << std::endl;
    is_running = true;
    count = 0;

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
        // TODO make FPS be a changeable option
        // 17 = ceil( 1 s / 60 fps )
        if(timer_fps < 17)
            SDL_Delay(17-timer_fps);
    }
}


void Game::render() {
    SDL_RenderClear(ren);
    map_manager.draw();
    e_man.draw();
    SDL_RenderPresent(ren);

}

void Game::update(){
    e_man.update();

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