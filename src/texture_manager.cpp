//
// Created by whiwho on 14/03/2020.
//

#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(const char* file_name, SDL_Renderer* ren){
    SDL_Surface* surf = IMG_Load(file_name);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren,surf);
    SDL_FreeSurface(surf);
    return tex;
}
