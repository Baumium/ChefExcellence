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

void Level::addEntity(Entity *entity) {
    entities.push_back(entity);
}

void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    //Draw background
    target.draw(backgroundSprite, states);

    //Draw the rest of the sprites
    for(Entity *entity : entities) {
        target.draw(*entity, states);
    }
}

void Level::update(sf::Time delta) {
    for(Entity *entity : entities) {
        entity->update(delta);
    }
}

std::vector<Entity*>& Level::getEntities() {
    return entities;
}
