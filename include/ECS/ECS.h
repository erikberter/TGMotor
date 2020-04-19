//
// Created by whiwho on 15/03/2020.
//

#ifndef TEMPGAMEMOTOR_ECS_H
#define TEMPGAMEMOTOR_ECS_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

#include <json.hpp>

class Component;
class Entity;
class Manager;

constexpr std::size_t max_components    = 32;
constexpr std::size_t max_groups        = 32;

using json = nlohmann::json;

namespace ComponentHelper{
    typedef std::map<std::string, std::function<Component*()>> map_type;
    typedef std::map<std::string,int> map_si;
    static map_type ComponentMap;
    static map_si TypeIDMap;
};

class Component{
public:
    Entity* entity;

    virtual void init(){};
    virtual void update(){};
    virtual void draw(){};
    virtual void set_data(json *data){};

    virtual ~Component(){};
};

class Entity{
private :
    Manager& manager;
    bool active = true;
    std::vector<Component* > components;

    std::map<std::string, Component*> component_array;
    std::bitset<max_components> component_bitset;
    std::bitset<max_groups> group_bitset;
public:

    Entity(Manager& manager_t) : manager(manager_t){}
    void update(){
        for(auto& c : components) c->update();
    };

    void draw(){
        for(auto& c : components) c->draw();
    }

    bool is_active(){return active;};
    void destroy(){active = false;};

    bool has_group(std::size_t group_t){
        return group_bitset[group_t];
    }

    void add_group(std::size_t group_t);
    void del_group(std::size_t group_t){
        group_bitset[group_t] = false;
    }

    bool has_component(std::string comp_name) const{
        return component_bitset[ComponentHelper::TypeIDMap[comp_name]];
    }

    void add_component(std::string comp_name, json *args){
        Component* c;
        if(!has_component(comp_name)){
            c = ComponentHelper::ComponentMap[comp_name]();

            c->entity = this;
            components.push_back(c);

            component_array[comp_name] = c;
            component_bitset[ComponentHelper::TypeIDMap[comp_name]] = true;

            c->init();
        }else
            c = component_array[comp_name];

        c->set_data(args);
    }
    void add_component(std::string comp_name){
        add_component(comp_name, new json("{}"));
    }

    Component* get_component(std::string comp_name){
        Component* ptr = component_array[comp_name];
        return ptr;
    }
};

class Manager{
private:
    std::vector<std::unique_ptr<Entity> > entities;
    std::array<std::vector<Entity*>, max_groups > grouped_entities;
public:
    void update(){
        for(auto& e : entities) e->update();
    };
    void draw(){
        for(auto& e : entities) e->draw();
    };

    void refresh(){

        for(auto i(0u); i < max_groups; i++){
            auto& v(grouped_entities[i]);
            v.erase(std::remove_if(std::begin(v), std::end(v), [i](Entity* entity_t){
                return !entity_t->is_active() || !entity_t->has_group(i);
            }), std::end(v));
        }

        entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entity> &mEntity){
            return !mEntity->is_active();
        }), std::end(entities));
    };

    void clear(){
        entities.clear();
        for(int i = 0; i < grouped_entities.size(); i++)
            grouped_entities[i].clear();
    }

    void add_group(Entity* entity, std::size_t group_t){
        grouped_entities[group_t].emplace_back(entity);
    }

    std::vector<Entity*>& get_group(std::size_t group_t){
        return grouped_entities[group_t];
    }

    Entity& add_entity(){
        Entity* e = new Entity(*this);
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};



#endif //TEMPGAMEMOTOR_ECS_H
