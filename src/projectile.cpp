#include "projectile.hpp"
#include "game.hpp"
#include <iostream>

Projectile::Projectile(const sf::Texture &texture, float speed, Direction direction, float x, float y) : Entity(texture), speed(speed), direction(direction) {
    move(x, y);
}

bool Projectile::isOffScreen(sf::Vector2f viewport) const {
    std::cout << getPosition().x << "\t" << viewport.x << std::endl;
    if(getPosition().x + getRect().width < viewport.x - Game::SCREEN_WIDTH
            || getPosition().x > viewport.x
            || getPosition().y + getRect().height < 0
            || getPosition().y > viewport.y) {
        return true;
    } else {
        return false;
    }
}

void Projectile::update() {
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
