#ifndef TEMPGAMEMOTOR_ENTITY_MANAGER_H
#define TEMPGAMEMOTOR_ENTITY_MANAGER_H


#include "ECS.h"
#include "physics/collision.h"

enum group_labels : std::size_t {
    G_PLAYER=1,G_ENEMY=2, G_COLLIDER=3, G_TILES=4
};

/**
 * The EntityManager class works by extending the Manager class
 * to add extra functionality.
 */
class EntityManager : public Manager{
private:
     std::vector<std::size_t> loading_order;
public:

    EntityManager();

    void draw_in_order();

    std::vector<Entity*>& get_entities(std::size_t identifier){return get_group(identifier);};

    /**
     * Sets the displacement of the Game Entities in order to be
     * rendered in some specific position in case is needed.
     */
    void set_displacement(int x, int y);


    void add_to_order(std::size_t order_t){loading_order.push_back(order_t);}
};


#endif //TEMPGAMEMOTOR_ENTITY_MANAGER_H
