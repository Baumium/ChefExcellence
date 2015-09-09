#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

class Entity : public sf::Drawable {
    private:
        sf::Sprite sprite;

    public:
        Entity(const sf::Texture &texture, sf::IntRect textureRect);
        Entity(const sf::Texture &texture);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
