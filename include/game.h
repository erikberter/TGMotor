#ifndef TEMPGAMEMOTOR_GAME_H
#define TEMPGAMEMOTOR_GAME_H

#include <iostream>
#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "stage.h"
#include "ECS/ECS.h"
#include "ECS/entity_manager.h"
#include "asset_manager.h"
#include "ECS/entity_gen.h"

#include <functional>

using json = nlohmann::json;

const unsigned short DEFAULT_FPS = 60;

class Game{
private:
    json config_json;

    bool running{false};
    int count{0u};
    unsigned int frame_count{0u}, timer_fps{0u},last_frame{0u};
    unsigned short FPS = DEFAULT_FPS;

    SDL_Event event{};

    std::map<std::string, G_Entity> g_entities;
    std::map<std::string, json> stages;

    void load_stages(const std::string& path);
    void load_g_entities(const std::string& path);
public:

    explicit Game(const std::string& config_file_path);
    ~Game() = default;

    void main_loop();
    void input();
    void update();
    void render();

    void load_defs(std::vector<std::string> *files);
    void read_config(const std::string& config_file_path);
    void set_stage(const std::string& stage_t);

    EntityManager e_man;

};

#endif //TEMPGAMEMOTOR_GAME_H
