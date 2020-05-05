#include "asset_manager.h"
#include "texture_manager.h"
#include <fstream>
#include <utils/files.h>
#include <plog/Log.h>

#include "g_constants.h"

void AssetManager::load_resources(SDL_Renderer* ren, const std::string& path){
    sp_str::functional_vector vc;

    sp_str::function_id_path function_png = [ren, this](const std::string& id, const std::string& path){
        this->add_texture(ren,id, path.c_str());
    };
    sp_str::function_id_path function_lst = [this](const std::string& id, const std::string& path){
        this->add_animation(id,path.c_str());
    };

    vc.push_back(std::make_pair(constants::ASSET_REGEX_PNG, function_png));
    vc.push_back(std::make_pair(constants::ASSET_REGEX_LST, function_lst));
    try{
        file_rec(path, vc);
    }catch(file_not_found_exception& fnf){
        PLOG_ERROR << fnf.what();
        PLOG_INFO << "Terminating.";
        std::terminate();
    }

    PLOG_DEBUG << "Default assets loaded.";
}

void AssetManager::add_texture(SDL_Renderer* tex, const std::string& id, const char* path){
    SDL_Texture *file_texture;
    try{
        file_texture = TextureManager::LoadTexture(tex, path);
    }catch(file_not_found_exception& fnf){
        PLOG_ERROR << fnf.what();
        std::terminate();
    }
    texture_map.emplace(id, file_texture);
}
SDL_Texture* AssetManager::get_texture(const std::string& id){
    return texture_map[id];
}

void AssetManager::add_animation(const std::string& id, const char* path){
    std::map<std::string, Animation> temp_a;
    std::ifstream animation_list_file(path);

    if(!animation_list_file.is_open()){
        PLOG_ERROR << "File not found: "  << path;
        std::terminate();
    }

    std::string anim_id;
    int n_anim_id=0,anim_f;
    while(animation_list_file >> anim_id >> anim_f)
        temp_a[anim_id]  = Animation(n_anim_id++,anim_f,100);

    texture_anim_map[id] = temp_a;
    animation_list_file.close();
}

std::map<std::string, Animation> AssetManager::get_animation_map(std::string& id){
    return texture_anim_map[id];
}

void AssetManager::clear_resources(){
    for(auto& texture : texture_map)
        SDL_DestroyTexture(texture.second);
    texture_map.clear();
    for(auto& entity : texture_anim_map)
        entity.second.clear();
    texture_anim_map.clear();
}
