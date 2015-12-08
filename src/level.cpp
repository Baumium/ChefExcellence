#include "level.hpp"
#include "game.hpp"
#include "staticentity.hpp"

Level::Level() {

}

void Level::setBackground(sf::Texture &texture) {
    backgroundSprite.setTexture(texture);
    backgroundSprite.setPosition(0, 0);
}

void Level::addEntity(sf::Texture &texture, sf::IntRect textureRect) {
    entities.push_back(new StaticEntity(texture, textureRect));
}

void Level::addEntity(sf::Texture &texture) {
    //TODO: implement adding of animated entities
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
