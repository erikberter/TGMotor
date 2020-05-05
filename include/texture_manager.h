#ifndef TEMPGAMEMOTOR_TEXTURE_MANAGER_H
#define TEMPGAMEMOTOR_TEXTURE_MANAGER_H

#include <SDL.h>
#include <TGMErrors.h>


class TextureManager{
public:
    static SDL_Texture* LoadTexture(SDL_Renderer* ren, const char* file_name) noexcept(false);
    static void draw(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};

#endif //TEMPGAMEMOTOR_TEXTURE_MANAGER_H
