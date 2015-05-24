#include "level.hpp"
#include "game.hpp"

Level::Level(sf::Texture &texture) : Entity(texture) {
    setPosition(0, 0);
}
