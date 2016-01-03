#ifndef ANIMATEDGRAPHICSMODULE_HPP
#define ANIMATEDGRAPHICSMODULE_HPP

#include <SFML/Graphics.hpp>
#include "entitystate.hpp"
#include "module.hpp"
#include "../AnimatedSprite.hpp"

class AnimatedGraphicsModule : public Module {
    private:
        AnimatedSprite sprite;
        std::map<EntityState, Animation> animations;

        EntityState currentState;
    public:
        AnimatedGraphicsModule();

        void addAnimation(EntityState state, Animation &animation);

        void draw(sf::RenderTarget &target, sf::RenderStates &states) const;
        void update(sf::Time &delta);

        void changeAnimation(EntityState state);

        void move(int x, int y);
        void setPosition(int x, int y);
        void setScale(float x, float y);
        sf::Vector2f getPosition() const;
        sf::FloatRect getRect() const;
};

#endif
