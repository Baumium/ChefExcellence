#ifndef MODULE_HPP
#define MODULE_HPP

#include <SFML/Graphics.hpp>
#include "moduletype.hpp"
#include "../entity.hpp"

class Module {
    private:
        ModuleType type;
    public:
        Module();

        virtual void update(sf::Time &delta, Entity &entity);
        virtual void draw(sf::RenderTarget &target, sf::RenderStates &states) const;
};

#endif
