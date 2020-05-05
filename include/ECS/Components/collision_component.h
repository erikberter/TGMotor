#ifndef TEMPGAMEMOTOR_COLLISION_COMPONENT_H
#define TEMPGAMEMOTOR_COLLISION_COMPONENT_H

#include "SDL.h"
#include "ECS/ECS.h"
#include "transform_component.h"

namespace ComponentHelper{
    extern ComponentHelper::ComponentType COLLISION;
}

class CollisionComponent : public Component {
private:
    TransformComponent* transf = nullptr;
    SDL_Rect coll{};
public:

    CollisionComponent() = default;

    void init() override{
        transf = dynamic_cast<TransformComponent*>(entity->add_component(ComponentHelper::TRANSFORM));
    }

    void update() override{
        coll = {static_cast<int>(transf->x()), static_cast<int>(transf->y()) ,
                transf->width*transf->scale, transf->height*transf->scale};
    }

    SDL_Rect get_coll() const{
        return coll;
    }
};

#endif //TEMPGAMEMOTOR_COLLISION_COMPONENT_H
