//
// Created by whiwho on 14/03/2020.
//

#include "entity.h"



Entity::Entity(const char* texture_sheet, SDL_Renderer *ren_t){
    coord_y = coord_x = 0;
    SDL_Rect init_src, init_dst;
    init_src.x = init_src.y = init_dst.x = init_dst.y = 0;
    init_src.w = init_src.h =init_dst.w =  init_dst.h = 50;

    dest = init_dst;
    src = init_src;
    ren = ren_t;
    tex = TextureManager::LoadTexture(texture_sheet, ren);
}

void Entity::set_dest(int x, int y, int w, int h){
    coord_y = y;
    coord_x = x;

    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;

}
void Entity::set_src(int x, int y, int w, int h){
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;

}
void Entity::set_texture(const char* texture_sheet, SDL_Renderer *ren){
    tex = TextureManager::LoadTexture(texture_sheet, ren);
}

void Entity::update(){
    coord_x++;
    coord_y++;
    dest.x = coord_x;
    dest.y = coord_y;
}

void Entity::render() {
    SDL_RenderCopy(ren, tex, &src,&dest);
}