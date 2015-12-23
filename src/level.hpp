#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <SFML/Graphics.hpp>
#include "direction.hpp"
#include "entity.hpp"
#include "Animation.hpp"

class Level : public sf::Drawable {
    private:
        sf::Sprite backgroundSprite;
        std::vector<Entity*> entities;

    public:
        Level();

        void setBackground(sf::Texture &texture);
        void addEntity(sf::Texture &texture, sf::IntRect textureRect);
        void addEntity(std::map<Direction, Animation> &animations);
        void addEntity(Entity *entity);

        void draw(sf::RenderTarget &target, sf::RenderStates states) const;
        void update(sf::Time delta);
        std::vector<Entity*>& getEntities();
};

#endif
