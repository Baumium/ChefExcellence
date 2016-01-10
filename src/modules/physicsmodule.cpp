#include "physicsmodule.hpp"
#include <iostream>

PhysicsModule::PhysicsModule() {
    //Set defaults
    movable = false;
    canFall = false;

    mass = 0;
    floorHeight = 0;

    velocity.x = 0;
    velocity.y = 0;
}

void PhysicsModule::update(sf::Time &delta, Entity &entity) {
    //Fall
    if(canFall) {
        if(entity.getPosition().y >= floorHeight) {
            velocity.y = 0;
            entity.setPosition(entity.getPosition().x, floorHeight);
        } else {
            velocity.y += gravity * delta.asSeconds();
            std::cout << delta.asSeconds() << std::endl;
        }
    }

    entity.move(velocity.x, velocity.y);
}

void PhysicsModule::setMovable(bool movable) {
    this->movable = movable;
}

bool PhysicsModule::getMovable() const {
    return movable;
}

void PhysicsModule::setFall(bool canFall) {
    this->canFall = canFall;
}

bool  PhysicsModule::getFall() const {
    return canFall;
}

void PhysicsModule::setMass(float mass) {
    this->mass = mass;
}

float PhysicsModule::getMass() const {
    return mass;
}

void PhysicsModule::setFloorHeight(float floorHeight) {
    this->floorHeight = floorHeight;
}

float PhysicsModule::getFloorHeight() const {
    return floorHeight;
}

void PhysicsModule::setGravity(float gravity) {
    this->gravity = gravity;
}

float PhysicsModule::getGravity() const {
    return gravity;
}
