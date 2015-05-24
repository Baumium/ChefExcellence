#include "projectile.hpp"
#include "game.hpp"
#include <iostream>

Projectile::Projectile(const sf::Texture &texture, float speed, Direction direction, float x, float y) : AnimatedSprite(sf::seconds(0.01), true, false), speed(speed), direction(direction) {
    int frameWidth = 816 / 17;
    int frameHeight = 48;

    setPosition(x - frameWidth / 2, y - frameHeight / 2);

    animation.setSpriteSheet(texture);

    animation.addFrame(sf::IntRect(0, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 2, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 3, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 4, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 5, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 6, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 7, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 8, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 9, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 10, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 11, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 12, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 13, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 14, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 15, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 16, 0, frameWidth, frameHeight));
    animation.addFrame(sf::IntRect(frameWidth * 17, 0, frameWidth, frameHeight));
}

bool Projectile::isOffScreen(sf::Vector2f viewport) const {
    std::cout << getPosition().x << "\t" << getPosition().y << std::endl;
    if(getPosition().x + getLocalBounds().width < viewport.x - Game::SCREEN_WIDTH
            || getPosition().x > viewport.x
            || getPosition().y + getLocalBounds().height < 0
            || getPosition().y > viewport.y) {
        return true;
    } else {
        return false;
    }
}

void Projectile::update(sf::Time deltaTime) {
    play(animation);
    AnimatedSprite::update(deltaTime);
    switch(direction) {
        case LEFT:
            move(-speed, 0);
            break;
        case RIGHT:
            move(speed, 0);
            break;
        case UP:
            move(0, -speed);
            break;
        case DOWN:
            move(0, speed);
            break;
        default:
            break;
    }
}
