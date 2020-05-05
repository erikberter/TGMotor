#include "game.h"

#include "g_constants.h"
#include <ECS/Components/component_helper_t.h>
#include <renderer.h>

#include "utils/files.h"
#include <plog/Log.h>


Game::Game(const std::string& config_file_path){
    plog::init(plog::debug, "logs/TGMotor.log");
    read_config(config_file_path);
}


void Game::load_defs(std::vector<std::string> *files){
    load_default_components();

    GameRender::ast_man.load_resources(GameRender::ren, "../res/assets/");
    load_g_entities("../res/entities/");
    load_stages("../res/stage/");

    // TODO Implement Extra resources loading
}

void Game::set_stage(const std::string& stage_t){
    e_man.clear();
    if(!stages.count(stage_t)){
        PLOG_ERROR << "Stage " << stage_t << " not found.";
        std::terminate();
    }

    json& stage_data = stages[stage_t];
    for(auto& entity_t : stage_data["entities"].items()){
        auto& new_entity = e_man.add_entity();
        // TODO Change to custom group inside the JSON
        new_entity.add_group(G_PLAYER);
        new_entity.add_components(entity_t.value()["components"]);
    }
}

void Game::main_loop() {
    running = true;
    while(running){
        last_frame = SDL_GetTicks();

        input();
        update();
        render();

        frame_count++;
        timer_fps = SDL_GetTicks()-last_frame;
        
        if(timer_fps < 1000/FPS)
            SDL_Delay(1000/FPS-timer_fps);
    }
}


void Game::render() {
    SDL_RenderClear(GameRender::ren);
    e_man.draw_in_order();
    SDL_RenderPresent(GameRender::ren);
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

void Game::load_g_entities(const std::string& path){
    std::map<std::string, G_Entity> *g_ent_vec_p = &g_entities;

    sp_str::function_id_path add_stage= [g_ent_vec_p](const std::string& a, const std::string& b){
        g_ent_vec_p->emplace(a, G_Entity(b));
    };

    sp_str::functional_vector vec_t = {std::make_pair(constants::ASSET_REGEX_PER, add_stage)};
    file_rec(path, vec_t);
    PLOG_DEBUG << "Entities loaded.";
}

void Game::load_stages(const std::string& path){
    std::map<std::string, json> *stage_vec_p = &stages;

    sp_str::function_id_path add_stage = [stage_vec_p](const std::string& a,const std::string& b){
        stage_vec_p->emplace(a, get_json(b));
    };

    sp_str::functional_vector vec_t = {std::make_pair(constants::ASSET_REGEX_STG, add_stage)};
    file_rec(path, vec_t);
    PLOG_DEBUG << "Stages loaded.";
}



void Game::read_config(const std::string& config_file_path){
    try{
        config_json = get_json(config_file_path);
    }catch(file_not_found_exception& fnf){
        PLOG_DEBUG << "No config file found. Moving one from default.";
        copy_file_from_to("../data/default/config.json","../data/config.json");
        config_json = get_json(config_file_path);
    }

    if(config_json.contains("FPS")) FPS = config_json["FPS"];
    else config_json = DEFAULT_FPS;
    PLOG_INFO << "Config file read.";
}
