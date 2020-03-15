//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_TEXTURE_MANAGER_H
#define TEMPGAMEMOTOR_TEXTURE_MANAGER_H

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_Image.h"

#include "game.h"

class TextureManager{
public :
    static SDL_Texture* LoadTexture(const char* file_name);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif //TEMPGAMEMOTOR_TEXTURE_MANAGER_H
