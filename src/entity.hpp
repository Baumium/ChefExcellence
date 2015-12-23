#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
        virtual void update(sf::Time deltaTime) = 0;

        virtual void move(int x, int y) = 0;
        virtual void setPosition(int x, int y) = 0;
        virtual void setScale(float x, float y) = 0;
        virtual sf::Vector2f getPosition() const = 0;
        virtual sf::FloatRect getRect() const = 0;
};

#endif
