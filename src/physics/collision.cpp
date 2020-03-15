//
// Created by whiwho on 15/03/2020.
//

#include "collision.h"

bool Collision::is_collision(SDL_Rect r1, SDL_Rect r2){
    // TODO Revisitar y mejorar
    return r1.x + r1.w >= r2.x && r2.x + r2.w >= r1.x && r1.y + r1.h >= r2.y && r2.y + r2.h >= r1.y;
}