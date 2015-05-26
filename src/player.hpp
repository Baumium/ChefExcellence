#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.hpp"
#include "direction.hpp"
#include "projectile.hpp"
#include "entity.hpp"

class Player : public AnimatedSprite {
    public:
        Player(const sf::Texture &texture, sf::Texture &breadstickTexture);

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void setPosition(float x, float y);
        void update(sf::Time deltaTime, sf::Vector2f viewport, std::vector<Entity> &platforms);
        void move(Direction hDirection);
        void jump();
        void throwBreadstick();

    private:
        //Animation
        Animation standingLeft;
        Animation standingRight;
        Animation walkingLeft;
        Animation walkingRight;
        Animation climbing;
        Animation currentAnimation;

        //Movement
        float maxHSpeed;
        float minHSpeed;
        float currentHSpeed;
        float hAcceleration;

        float maxVSpeed;
        float minVSpeed;
        float currentVSpeed;
        float vAcceleration;

        Direction facingDirection;
        Direction hDirection;
        Direction vDirection;

        bool canHMove;
        bool canVMove;


        //Breadstick projectile
        std::vector<Projectile> projectiles;
        sf::Texture breadstickTexture;
        float timeSinceThrowing;
        float breadstickDelay;
};


#endif
