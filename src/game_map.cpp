//
// Created by whiwho on 15/03/2020.
//

#include "game_map.h"
#include "texture_manager.h"
#include <fstream>

Game_map::Game_map(){
    load_default_assets();
}
Game_map::Game_map(int** map_t, int map_width_t, int map_height_t){
    map = new int*[map_height_t];
    for(int i = 0; i < map_height_t; i++){
        map[i] = new int[map_width_t];
        for(int j = 0; j < map_width_t; j++)
            map[i][j]  = map_t[i][j];
    }
    map_height = map_height_t;
    map_width = map_width_t;

    delete[] map_t;
    for(int i = 0; i < map_height_t; i++)
        delete[] map_t[i];
    load_default_assets();
}

Game_map::Game_map(const char* map_sheet){
    load_map(map_sheet);
    load_default_assets();
}

Game_map::~Game_map(){
    //SDL_DestroyTexture(grass);
    //SDL_DestroyTexture(water);
}

void Game_map::load_default_assets(){
    grass = TextureManager::LoadTexture("../res/tiles/grass-tile.png");
    water = TextureManager::LoadTexture("../res/tiles/water-tile.png");
}


void Game_map::load_map(const char* map_sheet){
    std::string file_name = map_sheet;
    std::string file_path = "../res/maps/"+file_name;
    std::ifstream infile(file_path);
    infile >> map_height >> map_width;
    reshape_map();
    for(int i = 0; i < map_height; i++)
        for(int j = 0; j < map_width; j++)
            infile >> map[i][j];
    infile.close();
}

#include <iostream>

void Game_map::print_map(){
    for(int i = 0; i < map_height; i++){
        for(int j = 0; j < map_width; j++){
            std::cout << map[i][j] << " ";

        }
        std::cout << std::endl;
    }
}

void Game_map::render_map(){
    SDL_Rect src, dest;
    src.x = src.y = dest.x = dest.y = 0;
    src.w = src.h = 50;
    dest.w = dest.h = 50;

    for(int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            if (map[i][j] == 0) TextureManager::draw(water, src, dest);
            else TextureManager::draw(grass, src, dest);
            dest.x+=50;
        }
        dest.x = 0;
        dest.y+=50;
    }
}

void Game_map::reshape_map(){
    map = new int*[map_height];
    for(int i = 0; i < map_height; i++)
        map[i] = new int[map_width];
}