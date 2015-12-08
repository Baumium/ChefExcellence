#include "animatedentity.hpp"

AnimatedEntity::AnimatedEntity(std::unordered_map<Direction, Animation> &animations) {
    sprite(
    this->animations = animations;
}

void AnimatedEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

void AnimatedEntity::update(float deltaTime) {
    sprite.update(deltaTime);
}

void AnimatedEntity::move(int x, int y) {
    sprite.move(x, y);
}

void AnimatedEntity::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void AnimatedEntity::setScale(float x, float y) {
    sprite.setScale(x, y);
}

sf::Vector2f AnimatedEntity::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect AnimatedEntity::getRect() const {
    return sprite.getGlobalBounds();
}

