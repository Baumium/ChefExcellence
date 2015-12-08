#ifndef ANIMATEDENTITY_HPP
#define ANIMATEDENTITY_HPP

#include "entity.hpp"
#include "AnimatedSprite.hpp"
#include <unordered_map>
#include "direction.hpp"

class AnimatedEntity : public Entity {
    private:
        AnimatedSprite sprite;
        std::unordered_map<Direction, Animation> animations;

    public:
        AnimatedEntity(std::unordered_map<Direction, Animation> &animations);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update(float deltaTime);

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
