//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_TEXTURE_MANAGER_H
#define TEMPGAMEMOTOR_TEXTURE_MANAGER_H

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_Image.h"

class TextureManager{
public :
    static SDL_Texture* LoadTexture(const char* file_name, SDL_Renderer* ren);
};

#endif //TEMPGAMEMOTOR_TEXTURE_MANAGER_H
