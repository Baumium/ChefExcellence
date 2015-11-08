#include "level.hpp"
#include "game.hpp"
#include <iostream>

Level::Level() {

}

void Level::setBackground(sf::Texture &texture) {
    backgroundSprite.setTexture(texture);
    backgroundSprite.setPosition(0, 0);
}

void Level::addEntity(sf::Sprite &sprite) {
    entities.push_back(new Entity(sprite));
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(backgroundSprite, states);

    for(Entity *entity : entities) {
        target.draw(*entity, states);
    }
}

std::vector<Entity*>& Level::getEntities() {
    return entities;
}
