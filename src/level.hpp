#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "AnimatedSprite.hpp"

class Level : public sf::Drawable {
    private:
        sf::Sprite backgroundSprite;
        std::vector<Entity*> entities;

    public:
        Level();

        void setBackground(sf::Texture &texture);
        void addEntity(sf::Texture &texture, sf::IntRect textureRect);
        void addEntity(sf::Texture &texture);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void update(float delta);
        std::vector<Entity*>& getEntities();
};

#endif
