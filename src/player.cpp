#include "player.hpp"
#include "game.hpp"
#include <iostream>

Player::Player(const sf::Texture &texture, sf::Texture &breadstickTexture) :
    AnimatedSprite(sf::seconds(0.1), true, false), breadstickTexture(breadstickTexture) {

    //Set up animations
    setPosition(0, 0);

    walkingRight.setSpriteSheet(texture);
    walkingRight.addFrame(sf::IntRect(0, 0, 91 / 3.0, 73));
    walkingRight.addFrame(sf::IntRect(91 / 3.0, 0, 91 / 3.0, 73));
    walkingRight.addFrame(sf::IntRect(91 / 3.0 * 2, 0, 91 / 3.0, 73));

    standingRight.setSpriteSheet(texture);
    standingRight.addFrame(sf::IntRect(0, 0, 91 / 3.0, 73));

    currentAnimation = standingRight;

    //Movement
    facingDirection = RIGHT;
    hDirection = NONE;
    vDirection = NONE;

    maxHSpeed = 5;
    minHSpeed = 2;
    currentHSpeed = minHSpeed;
    hAcceleration = 1.1;

    maxVSpeed = 10;
    minVSpeed = 2;
    currentVSpeed = maxVSpeed;
    vAcceleration = 0.9;

    //Breadstick projectile
    timeSinceThrowing = 0;
    breadstickDelay = 500;
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //Draw breadsticks
    for(uint i = 0; i < projectiles.size(); i++) {
        target.draw(projectiles.at(i).getSprite(), states);
    }

    //Draw player
    AnimatedSprite::draw(target, states);
}

void Player::setPosition(float x, float y) {
    AnimatedSprite::setPosition(x, y);
}

void Player::move(Direction hDirection) {
    if(this->hDirection != hDirection) {
        currentHSpeed = minHSpeed;
        this->hDirection = hDirection;
    }
}

void Player::jump() {
    if(vDirection != DOWN) {
        vDirection = UP;
    }
}

void Player::throwBreadstick() {
    if(timeSinceThrowing > breadstickDelay) {
        timeSinceThrowing = 0;
        Projectile projectile(breadstickTexture, 8, facingDirection, getPosition().x, getPosition().y);
        projectiles.push_back(projectile);
    }
}

void Player::update(sf::Time deltaTime, sf::Vector2f viewport) {
    //Update animation
    play(currentAnimation);
    AnimatedSprite::update(deltaTime);

    //Move left and right
    switch(hDirection) {
        case LEFT:
            facingDirection = LEFT;
            AnimatedSprite::move(-currentHSpeed, 0);
            if(currentHSpeed < maxHSpeed) {
                currentHSpeed *= hAcceleration;
            }
            break;
        case RIGHT:
            currentAnimation = walkingRight;
            facingDirection = RIGHT;
            AnimatedSprite::move(currentHSpeed, 0);
            if(currentHSpeed < maxHSpeed) {
                currentHSpeed *= hAcceleration;
            }
            break;
        default:
            if(facingDirection == RIGHT) {
                currentAnimation = standingRight;
            } else {
                //TODO: currentAnimation = standingLeft
                currentAnimation = standingRight;
            }
            break;
    }

    //Move up and down
    switch(vDirection) {
        case UP:
            AnimatedSprite::move(0, -currentVSpeed);
            currentVSpeed *= vAcceleration;
            if(currentVSpeed < minVSpeed) {
                vDirection = DOWN;
            }
            //If touching top of screen, stop jumping (TEMP)
            if(getPosition().y <= 0) {
                vDirection = NONE;
            }
            break;
        case DOWN:
            AnimatedSprite::move(0, currentVSpeed);
            //Fix player getting moved off screen
            if(getPosition().y + getLocalBounds().height > Game::SCREEN_HEIGHT) {
                setPosition(getPosition().x, Game::SCREEN_HEIGHT - getLocalBounds().height);
            }

            //If touching bottom of screen, stop falling
            if(getPosition().y + getLocalBounds().height >= Game::SCREEN_HEIGHT) {
                vDirection = NONE;
            }

            //Adjust speed
            if(currentVSpeed < maxVSpeed) {
                currentVSpeed /= vAcceleration;
            }
            break;
        case NONE:
            //If player is not touching bottom of screen, fall
            if(getPosition().y + getLocalBounds().height < Game::SCREEN_HEIGHT) {
                vDirection = DOWN;
            }
        default:
            break;
    }

    //Update projectiles
    timeSinceThrowing += deltaTime.asMilliseconds();
    for(uint i = 0; i < projectiles.size(); i++) {
        projectiles.at(i).update();
        if(projectiles.at(i).isOffScreen(viewport)) {
            projectiles.erase(projectiles.begin() + i);
        }
    }

}
