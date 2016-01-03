#ifndef PHYSICSMODULE_HPP
#define PHYSICSMODULE_HPP

#include "module.hpp"

class PhysicsModule : public Module {
    private:
        bool movable;
        bool canFall;

        float mass;
        float floorHeight;
        float gravity;

    public:
        PhysicsModule();

        void update(sf::Time &delta, Entity &entity);

        void setMovable(bool movable);
        bool getMovable() const;

        void setFall(bool canFall);
        bool getFall() const;

        void setMass(float mass);
        float getMass() const;

        void setFloorHeight(float floorHeight);
        float getFloorHeight() const;

        void setGravity(float gravity);
        float getGravity() const;
};

#endif
