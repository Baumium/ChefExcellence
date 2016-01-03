#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "modules/direction.hpp"

class Projectile : public AnimatedSprite {
    private:
        Animation animation;
        float speed;
        Direction direction;

    public:
        Projectile(const sf::Texture &texture, float speed, Direction direction, float x, float y);
        bool isOffScreen(sf::Vector2f viewport) const;
        void update(sf::Time deltaTime);
};

#endif
