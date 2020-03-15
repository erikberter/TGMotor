//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_GAME_H
#define TEMPGAMEMOTOR_GAME_H

#include <iostream>
#include <vector>

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_Image.h"


const int WIDTH = 800, HEIGH = 600;

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

    static SDL_Renderer *ren;
    static SDL_Event event;
};

#endif //TEMPGAMEMOTOR_GAME_H
