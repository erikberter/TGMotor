//
// Created by whiwho on 15/03/2020.
//

#include "game_map.h"
#include "texture_manager.h"
#include <fstream>

#include "ECS/Components/transform_component.h"
#include "ECS/Components/sprite_component.h"

GameMap::GameMap(int** map_t, int map_width_t, int map_height_t){
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
}

GameMap::GameMap(const char* map_sheet, Game *gApp){
    load_map(map_sheet,gApp);
}

GameMap::~GameMap(){
    //SDL_DestroyTexture(grass);
    //SDL_DestroyTexture(water);
}



void GameMap::load_map(const char* map_sheet, Game *gApp){
    file_name = map_sheet;
    std::string file_path = "../res/maps/"+file_name+".map";
    std::string res_path = "../res/maps/"+file_name+".res";
    std::ifstream res_infile(res_path);
    std::map<int, std::string> tex_map;
    int n_lines;
    res_infile >> n_lines;
    for(int i = 0; i< n_lines; i++){
        std::string tile_name;
        int id;
        res_infile >> id >> tile_name;
        tex_map[id] =  ("../res/tiles/" +tile_name);
    }
    res_infile.close();
    std::ifstream map_infile(file_path);
    map_infile >> map_height >> map_width;
    reshape_map();
    int x = 0, y = 0, map_id = 0;
    // Se puede cambiar x,y por i*50, j*50, pero no se que es mejor

    for(int i = 0; i < map_height; i++){
        for(int j = 0; j < map_width; j++){
            map_infile >> map[i][j];
            {
                auto& tile = gApp->e_man.man.add_entity();
                tile.add_component<TransformComponent>(j*50,i*50,50,50,1);
                tile.add_component<SpriteComponent>(tex_map[map[i][j]].c_str(),gApp);
                tile.add_group(G_TILES);
            }
        }
    }
    map_infile.close();
}

#include <iostream>

void GameMap::print_map(){
    for(int i = 0; i < map_height; i++){
        for(int j = 0; j < map_width; j++)
            std::cout << map[i][j] << " ";
        std::cout << std::endl;
    }
}


void GameMap::reshape_map(){
    map = new int*[map_height];
    for(int i = 0; i < map_height; i++)
        map[i] = new int[map_width];
}

