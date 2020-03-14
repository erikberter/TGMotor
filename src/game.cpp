//
// Created by whiwho on 14/03/2020.
//

#include "game.h"

Game::Game(){
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGH, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Eralia");

    Entity star("../res/sprite/star.png",ren);
    star.set_src(0,0,75,75);
    star.set_dest(50,50,100,100);
    entity_list.push_back(star);
    Entity star2("../res/sprite/star.png",ren);
    star2.set_src(0,0,75,75);
    star2.set_dest(150,150,100,100);
    entity_list.push_back(star2);
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
        if(timer_fps < 1000/60)
            SDL_Delay(1000/60-timer_fps);


        if(count>3) is_running=false;

    }

}

void Game::render() {

    SDL_RenderClear(ren);

    SDL_SetRenderDrawColor(ren, 255,0,0,255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 360;
    rect.h = 240;

    SDL_RenderFillRect(ren, &rect);
    for(Entity ent : entity_list)
        ent.render();


    SDL_RenderPresent(ren);

}

void Game::update(){
    for(int i = 0; i < entity_list.size(); i++)
        entity_list[i].update();
}

void Game::input(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            is_running = false;
            break;

        default:
            break;
    }
}

void Game::draw(Entity o){
    SDL_Rect dest = o.get_dest();
    SDL_Rect src = o.get_src();
    SDL_RenderCopyEx(ren, o.get_tex(), &src, &dest,0, NULL, SDL_FLIP_NONE);
}