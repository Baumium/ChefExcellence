#include "entity.hpp"


Entity::Entity(const sf::Texture &texture) : sprite(texture) {

}

Entity::Entity(const sf::Texture &texture, sf::IntRect textureRect) : sprite(texture) {
    sprite.setTextureRect(textureRect);
}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void Entity::move(int x, int y) {
    sprite.move(x, y);
}

void Entity::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void Entity::setScale(float x, float y) {
    sprite.setScale(x, y);
}

sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect Entity::getRect() const {
    return sprite.getGlobalBounds();
}

