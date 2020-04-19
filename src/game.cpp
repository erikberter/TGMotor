//
// Created by whiwho on 14/03/2020.
//
#include "game.h"

#include "g_constants.h"
#include <ECS/Components/component_helper_t.h>
#include <renderer.h>

#include "utils/files.h"




Game::Game(std::string config_file_path){
    read_config(config_file_path);
}

void Game::load_defs(std::vector<std::string> files){
    SDL_Renderer **ren = GameRender::ren;
    // First load the default asset file
    load_components();
    GameRender::ast_man.load_resources(ren, "../res/assets/");
    load_g_entities("../res/entities/");
    load_stages("../res/stage/");
}

void Game::set_stage(std::string stage_t){
    e_man.man.clear();
    if(!stages.count(stage_t))
        return; // TODO Add error in case no stage found

    json *stage_data = &stages[stage_t];
    if(stage_data->contains("entities")){
        for(auto& c : (*stage_data)["entities"].items()){
            auto& temp_ent = e_man.man.add_entity();
            temp_ent.add_group(G_PLAYER);
            if(!c.value().contains("components"))
                continue;
            for(auto& c_comp : c.value()["components"].items())
                temp_ent.add_component(static_cast<std::string>(c_comp.key()), &c_comp.value());
        }
    }
}
Game::~Game(){
    running = false;
}

void Game::main_loop() {
    running = true;
    static int last_time=0;
    while(running){

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
    SDL_RenderClear(*GameRender::ren);
    e_man.draw();
    SDL_RenderPresent(*GameRender::ren);

}

void Game::update(){
    e_man.update();

}

void Game::input(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            running = false;
            break;
        default:
            break;
    }
}

void Game::load_g_entities(std::string path){
    std::string stg_regex = constants::ASSET_REGEX_PER;
    std::vector<G_Entity> *g_ent_vec_p = &g_entities;

    std::function<void(std::string, std::string)> add_stage= [g_ent_vec_p](std::string a, std::string b){
        g_ent_vec_p->push_back(G_Entity(b));
    };

    std::vector<std::pair<std::string, std::function< void(std::string, std::string)> > > vec_t = {std::make_pair(stg_regex, add_stage)};
    file_rec(path, vec_t);
}

void Game::load_stages(std::string path){
    std::string stg_regex = constants::ASSET_REGEX_STG;
    std::map<std::string, json> *stage_vec_p = &stages;

    std::function<void(std::string, std::string)> add_stage= [stage_vec_p](std::string a, std::string b){

        stage_vec_p->emplace(a, get_json(b));
    };

    std::vector<std::pair<std::string, std::function< void(std::string, std::string)> > > vec_t = {std::make_pair(stg_regex, add_stage)};
    file_rec(path, vec_t);
}



void Game::read_config(std::string config_file_path){
    return;
}