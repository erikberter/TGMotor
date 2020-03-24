//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_COLLISION_COMPONENT_H
#define TEMPGAMEMOTOR_COLLISION_COMPONENT_H

#include "game.h"
#include "SDL.h"
#include "ECS/ECS.h"
#include "transform_component.h"


class CollisionComponent : public Component {

private:
    TransformComponent* transf;
public:
    SDL_Rect coll;
    CollisionComponent() = default;

    void init() override{
        if(!entity->has_component<TransformComponent>())
            entity->add_component<TransformComponent>();
        transf = &entity->get_component<TransformComponent>();
        // TODO abstract this
        Game::colliders.push_back(this);

    }

    void update() override{
        coll.x = static_cast<int>(transf->x());
        coll.y = static_cast<int>(transf->y());
        coll.w = transf->width*transf->scale;
        coll.h = transf->height*transf->scale;
    }


};

#endif //TEMPGAMEMOTOR_COLLISION_COMPONENT_H
