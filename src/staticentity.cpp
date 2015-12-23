#include "staticentity.hpp"

StaticEntity::StaticEntity(const sf::Texture &texture, sf::IntRect textureRect) {
    sprite.setTexture(texture);
    sprite.setTextureRect(textureRect);
}

void StaticEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void StaticEntity::update(sf::Time delta) {

}

void StaticEntity::move(int x, int y) {
    sprite.move(x, y);
}

void StaticEntity::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void StaticEntity::setScale(float x, float y) {
    sprite.setScale(x, y);
}

sf::Vector2f StaticEntity::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect StaticEntity::getRect() const {
    return sprite.getGlobalBounds();
}
