#include "controlmodule.hpp"
#include <iostream>

ControlModule::ControlModule() {

}

void ControlModule::update(sf::Time &delta, Entity &entity) {
    //std::cout << keys.size() << std::endl;
    for(auto key = keys.begin(); key != keys.end(); key++) {
        if (sf::Keyboard::isKeyPressed(key->second)) {
            entity.setState(key->first);
        }
    }
}

void ControlModule::addKey(EntityState &state, sf::Keyboard::Key &key) {
    keys.insert(std::pair<EntityState, sf::Keyboard::Key>(state, key));
    std::cout << keys.size() << std::endl;
}
