#include "entity.hpp"
#include <iostream>
#include "modules/animatedgraphicsmodule.hpp"

Entity::Entity() {
    //Defaults
    state.setAction(STANDING);
    state.setDirection(RIGHT);
}

void Entity::addModule(ModuleType type, Module *module) {
    modules.insert(std::pair<ModuleType, Module*>(type, module));
}

void Entity::update(sf::Time &delta) {
    for(auto iterator = modules.begin(); iterator != modules.end(); iterator++) {
        iterator->second->update(delta, *this);
    }
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto iterator = modules.begin(); iterator != modules.end(); iterator++) {
        iterator->second->draw(target, states);
    }
}

void Entity::setState(EntityState state) {
    this->state = state;
    if(modules.count(GRAPHICS) > 0) {
        static_cast<AnimatedGraphicsModule*>(modules.at(GRAPHICS))->changeAnimation(state);
    }
}

EntityState Entity::getState() const {
    return state;
}

void Entity::setPosition(int x, int y) {
    if(modules.count(GRAPHICS) > 0) {
       static_cast<AnimatedGraphicsModule*>(modules.at(GRAPHICS))->setPosition(x, y);
    }
}

sf::Vector2f Entity::getPosition() const {
    if(modules.count(GRAPHICS) > 0) {
        return static_cast<AnimatedGraphicsModule*>(modules.at(GRAPHICS))->getPosition();
    } else {
        return sf::Vector2f();
    }
}

void Entity::move(int x, int y) {
    if(modules.count(GRAPHICS) > 0) {
        static_cast<AnimatedGraphicsModule*>(modules.at(GRAPHICS))->move(x, y);
    }
}

