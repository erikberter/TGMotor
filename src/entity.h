//
// Created by whiwho on 14/03/2020.
//

#ifndef TEMPGAMEMOTOR_ENTITY_H
#define TEMPGAMEMOTOR_ENTITY_H

#include "game.h"

#include "texture_manager.h"

class Entity_t {

private:
    int coord_x, coord_y;
    SDL_Rect dest, src;
    SDL_Texture* tex;

public:
    Entity_t() {};
    Entity_t(const char* texture_sheet);

    void update();
    void render();

    SDL_Rect get_dest(){ return dest;}
    SDL_Rect get_src(){return src;}
    SDL_Texture* get_tex(){return tex;}
    void set_dest(int x, int y, int w, int h);
    void set_src(int x, int y, int w, int h);
    void set_texture(const char* texture_sheet);
};


#endif //TEMPGAMEMOTOR_ENTITY_H
