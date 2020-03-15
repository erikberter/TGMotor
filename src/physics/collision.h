//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_COLLISION_H
#define TEMPGAMEMOTOR_COLLISION_H

#include "SDL.h"

class Collision{
public:
    static bool is_collision(SDL_Rect r1, SDL_Rect r2);
};

#endif //TEMPGAMEMOTOR_COLLISION_H
