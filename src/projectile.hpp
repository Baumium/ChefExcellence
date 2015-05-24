#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "direction.hpp"

class Projectile : public Entity {
    private:
        float speed;
        Direction direction;

    public:
        Projectile(const sf::Texture &texture, float speed, Direction direction, float x, float y);
        bool isOffScreen(sf::Vector2f viewport) const;
        void update();
};

#endif
