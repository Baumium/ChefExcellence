#ifndef CONTROLMODULE_HPP
#define CONTROLMODULE_HPP

#include "module.hpp"
#include "entitystate.hpp"

class ControlModule : public Module {
    private:
        std::map<EntityState, sf::Keyboard::Key> keys;

    public:
        ControlModule();

        void update(sf::Time &delta, Entity &entity);

        void addKey(EntityState &state, sf::Keyboard::Key &key);
};

#endif
