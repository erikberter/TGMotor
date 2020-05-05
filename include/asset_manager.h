#ifndef TEMPGAMEMOTOR_ASSET_MANAGER_H
#define TEMPGAMEMOTOR_ASSET_MANAGER_H


#include <map>
#include "ECS/ECS.h"
#include <SDL.h>
#include "ECS/animation.h"


class AssetManager {
private:
    std::map<std::string, SDL_Texture*> texture_map;
    std::map<std::string, std::map<std::string, Animation> > texture_anim_map;
public:

    AssetManager() = default;
    ~AssetManager() = default;

    void load_resources(SDL_Renderer* ren, const std::string& path);
    void clear_resources();

    void add_texture(SDL_Renderer* tex, const std::string& id, const char* path);
    SDL_Texture* get_texture(const std::string& id);

    void add_animation(const std::string& id, const char* path);
    std::map<std::string, Animation> get_animation_map(std::string& id);
};


#endif //TEMPGAMEMOTOR_ASSET_MANAGER_H
