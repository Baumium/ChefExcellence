#ifndef LEVEL_HPP
#define LEVEL_HPP

#include "entity.hpp"

class Level : public Entity {
    private:
        std::vector<Entity> platforms;

    public:
        Level(sf::Texture &backgroundTexture, sf::Texture &platformTexture);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        std::vector<Entity>& getPlatforms();
};

#endif
