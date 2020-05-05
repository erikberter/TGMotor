#include <SDL_image.h>

#include "texture_manager.h"

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* ren, const char* file_name){
    SDL_Surface* surf = IMG_Load(file_name);
    if(!surf) throw file_not_found_exception(file_name);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren,surf);
    SDL_FreeSurface(surf);
    return tex;
}
void TextureManager::draw(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest){
    SDL_RenderCopy(ren, tex,&src,&dest);
}