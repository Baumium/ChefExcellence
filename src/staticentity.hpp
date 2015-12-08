#ifndef STATICENTITY_HPP
#define STATICENTITY_HPP

#include "entity.hpp"

class StaticEntity : public Entity {
    private:
        sf::Sprite sprite;

    public:
        StaticEntity(const sf::Texture &texture, sf::IntRect textureRect);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update(float deltaTime);

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
