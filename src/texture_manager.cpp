//
// Created by whiwho on 14/03/2020.
//

#include "texture_manager.h"
#include <fstream>
SDL_Renderer** TextureManager::ren = nullptr;

SDL_Texture* TextureManager::LoadTexture(const char* file_name){
    std::ifstream f(file_name);
    SDL_Surface* surf = IMG_Load(file_name);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(*(TextureManager::ren),surf);
    SDL_FreeSurface(surf);
    return tex;
}
void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(*(TextureManager::ren), tex,&src,&dest);
}