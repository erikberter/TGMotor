#ifndef GAME_MOTOR_COMPONENT_HELPER_T_H
#define GAME_MOTOR_COMPONENT_HELPER_T_H

#include <plog/Log.h>
#include "ECS/ECS.h"
#include "transform_component.h"
#include "sprite_component.h"
#include "collision_component.h"

using namespace ComponentHelper;

void add_new_component_meta(ComponentHelper::ComponentType comp_id, const std::string& comp_name, std::function<Component*()> creator){
    if(ComponentMap.count(comp_id)){

        std::string used_component_name = std::find_if(
                ComponentMapSCT.begin(), ComponentMapSCT.end(),
                [comp_id](const auto& map_comp_id) {return map_comp_id.second == comp_id; }
                )->first;
        PLOG_ERROR << "Tried to add new Component over used id. \nTried: " << comp_id << " : " << comp_name
            <<". Which is used by " << used_component_name;
        std::terminate();
    }
    ComponentMap[comp_id] = {std::move(creator)};
    ComponentMapSCT[comp_name] = comp_id;
}

void load_default_components(){
    add_new_component_meta(ComponentHelper::TRANSFORM,
            "transform",[]() -> TransformComponent* {return new TransformComponent;});
    add_new_component_meta(ComponentHelper::COLLISION,
            "collision", []() -> CollisionComponent* {return new CollisionComponent;});
    add_new_component_meta(ComponentHelper::SPRITE,
            "sprite", []() -> SpriteComponent* {return new SpriteComponent;});
}

#endif //GAME_MOTOR_COMPONENT_HELPER_T_H
