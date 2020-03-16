//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_GAME_MAP_H
#define TEMPGAMEMOTOR_GAME_MAP_H


#include <SDL_render.h>
#include "ECS/ECS.h"

class Game_map {
private:
    int map_width, map_height;
    int** map;

    SDL_Texture* grass;
    SDL_Texture* water;

public:

    Game_map();
    Game_map(int** map_t, int map_width_t, int map_height_t);
    Game_map(const char* map_sheet);

    ~Game_map();


    void load_default_assets();

    void load_map(const char* map_sheet);
    void print_map();
    void reshape_map();

    int get_map_width(){return map_width;}
    int get_map_height(){return map_height;}

};


#endif //TEMPGAMEMOTOR_GAME_MAP_H
