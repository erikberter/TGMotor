//
// Created by whiwho on 18/04/2020.
//

#ifndef GAME_MOTOR_COMPONENT_HELPER_T_H
#define GAME_MOTOR_COMPONENT_HELPER_T_H

#include "ECS/ECS.h"
#include "transform_component.h"
#include "sprite_component.h"
#include "collision_component.h"

void load_components(){
    ComponentHelper::ComponentMap["transform"] = []() -> TransformComponent* {return new TransformComponent;};
    ComponentHelper::ComponentMap["collision"] = []() -> CollisionComponent* {return new CollisionComponent;};
    ComponentHelper::ComponentMap["sprite"] = []() -> SpriteComponent* {return new SpriteComponent;};

    ComponentHelper::TypeIDMap["transform"] = 1;
    ComponentHelper::TypeIDMap["collision"] = 2;
    ComponentHelper::TypeIDMap["sprite"] = 3;
}


#endif //GAME_MOTOR_COMPONENT_HELPER_T_H
