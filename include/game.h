//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_GAME_H
#define TEMPGAMEMOTOR_GAME_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "stage.h"
#include "ECS/ECS.h"
#include "ECS/entity_manager.h"
#include "ECS/asset_manager.h"
#include "ECS/entity_gen.h"

#include <functional>


const int WIDTH = 800, HEIGH = 600;



using json = nlohmann::json;

class Game{
private:
    // Game Metadata
    bool running;

    bool map_loaded;
    int count;

    // Game Value
    int frame_count, timer_fps,last_frame;

    SDL_Event event;

    void load_stages(std::string path);
    void load_g_entities(std::string path);
public:
    // TODO Move to private
    std::vector<G_Entity> g_entities;
    std::map<std::string, json> stages;
    Game() = default;
    Game(std::string config_file_path);
    ~Game();

    // TODO Maybe improve with templates
    void load_defs(std::vector<std::string> files);

    void main_loop();

    void input();
    void update();
    void render();

    void read_config(std::string config_file_path);

    void set_stage(std::string stage_t);

    EntityManager e_man;

};

#endif //TEMPGAMEMOTOR_GAME_H
