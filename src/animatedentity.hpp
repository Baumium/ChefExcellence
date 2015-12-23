#ifndef ANIMATEDENTITY_HPP
#define ANIMATEDENTITY_HPP

#include "entity.hpp"
#include "AnimatedSprite.hpp"
#include <map>
#include "direction.hpp"

class AnimatedEntity : public Entity {
    private:
        AnimatedSprite sprite;
        std::map<Direction, Animation> animations;

        Direction currentState;

    public:
        AnimatedEntity(std::map<Direction, Animation> &animations);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update(sf::Time deltaTime);

        void changeAnimation(Direction state);

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
