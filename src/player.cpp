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

    maxHSpeed = 4;
    minHSpeed = 1.5;
    currentHSpeed = minHSpeed;
    hAcceleration = 1.05;

    maxVSpeed = 10;
    minVSpeed = 2;
    currentVSpeed = maxVSpeed;
    vAcceleration = 0.9;

    canHMove = true;
    canVMove = true;

    //Breadstick projectile
    timeSinceThrowing = 0;
    breadstickDelay = 500;
}


void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //Draw breadsticks
    for(uint i = 0; i < projectiles.size(); i++) {
        target.draw(projectiles.at(i), states);
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
    if(vDirection != DOWN && vDirection != UP) {
        vDirection = UP;
        //Reset jump speed
        currentVSpeed = maxVSpeed;
    }
}

void Player::throwBreadstick() {
    if(timeSinceThrowing > breadstickDelay) {
        timeSinceThrowing = 0;
        Projectile projectile(breadstickTexture, 8, facingDirection, getPosition().x + getGlobalBounds().width / 2, getPosition().y + getGlobalBounds().height / 2);
        projectiles.push_back(projectile);
    }
}

void Player::update(sf::Time deltaTime, sf::Vector2f viewport, std::vector<Entity> &platforms) {
    //Update animation
    play(currentAnimation);
    AnimatedSprite::update(deltaTime);

    //Collision detection with level platforms
    for(auto &platform : platforms) {
        //Chef (like check...except chef) x collisions if y positions match up
        if(platform.getPosition().y <= getPosition().y + getGlobalBounds().height
                && platform.getPosition().y + platform.getRect().height >= getPosition().y) {
            if((hDirection == LEFT
                    && getPosition().x - currentHSpeed < platform.getPosition().x + platform.getRect().width
                    && getPosition().x + getGlobalBounds().width - currentHSpeed > platform.getPosition().x)
                    || (hDirection == RIGHT
                        && getPosition().x + getGlobalBounds().width + currentHSpeed > platform.getPosition().x
                        && getPosition().x + currentHSpeed < platform.getPosition().x + platform.getRect().width)) {
                canHMove = false;
            } else {
                canHMove = true;
            }

        } else {
            canHMove = true;
        }

        //Check y collisions
        if(platform.getPosition().y <= getPosition().y + getGlobalBounds().height + currentVSpeed
                && platform.getPosition().y + platform.getRect().height > getPosition().y) {
            if((vDirection == DOWN
                    && getPosition().x + getGlobalBounds().width >= platform.getPosition().x
                    && getPosition().x <= platform.getPosition().x + platform.getRect().width)) {
                canVMove = false;
            } else {
                canVMove = true;
            }
        }
    }

    //Move left and right
    switch(hDirection) {
        case LEFT:
            if(canHMove) {
                facingDirection = LEFT;
                AnimatedSprite::move(-currentHSpeed, 0);
                if(currentHSpeed < maxHSpeed) {
                    currentHSpeed *= hAcceleration;
                }
            } else {
                currentHSpeed = minHSpeed;
            }
            break;
        case RIGHT:
            if(canHMove) {
                currentAnimation = walkingRight;
                facingDirection = RIGHT;
                AnimatedSprite::move(currentHSpeed, 0);
                if(currentHSpeed < maxHSpeed) {
                    currentHSpeed *= hAcceleration;
                }
            } else {
                currentHSpeed = minHSpeed;
            }
            break;
        default:
            if(facingDirection == RIGHT) {
                currentAnimation = standingRight;
            } else {
                //TODO: currentAnimation = standingLeft
                currentAnimation = standingRight;
            }
            currentHSpeed = minHSpeed;
            break;
    }

    //Move up and down
    switch(vDirection) {
        case UP:
            if(canVMove) {
                AnimatedSprite::move(0, -currentVSpeed);
                currentVSpeed *= vAcceleration;
                if(currentVSpeed < minVSpeed) {
                    vDirection = DOWN;
                }
            }
            break;
        case DOWN:
            if(canVMove) {
                AnimatedSprite::move(0, currentVSpeed);
                //Fix player getting moved off screen
                if(getPosition().y + getGlobalBounds().height > Game::SCREEN_HEIGHT) {
                    setPosition(getPosition().x, Game::SCREEN_HEIGHT - getGlobalBounds().height);
                }

                //If touching bottom of screen, stop falling
                if(getPosition().y + getGlobalBounds().height >= Game::SCREEN_HEIGHT) {
                    vDirection = NONE;
                }

                //Adjust speed
                if(currentVSpeed < maxVSpeed) {
                    currentVSpeed /= vAcceleration;
                }
            } else {
                vDirection = NONE;
            }
            break;
        case NONE:
            //If player is not touching bottom of screen, fall
            if(canVMove && getPosition().y + getGlobalBounds().height < Game::SCREEN_HEIGHT) {
                vDirection = DOWN;
                //Reset fall speed
                currentVSpeed = minVSpeed;
            }
        default:
            break;
    }

    //Update projectiles
    timeSinceThrowing += deltaTime.asMilliseconds();
    for(uint i = 0; i < projectiles.size(); i++) {
        projectiles.at(i).update(deltaTime);
        if(projectiles.at(i).isOffScreen(viewport)) {
            projectiles.erase(projectiles.begin() + i);
        }
    }

}
