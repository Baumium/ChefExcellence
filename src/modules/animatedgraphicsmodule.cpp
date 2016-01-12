#include "animatedgraphicsmodule.hpp"
#include <iostream>

AnimatedGraphicsModule::AnimatedGraphicsModule() {

}

void AnimatedGraphicsModule::addAnimation(EntityState state, Animation &animation) {
    animations.insert(std::pair<EntityState, Animation>(state, animation));
}

void AnimatedGraphicsModule::draw(sf::RenderTarget &target, sf::RenderStates &states) const {
    target.draw(sprite, states);
}

void AnimatedGraphicsModule::update(sf::Time &delta, Entity &entity) {
    sprite.update(delta);
}

void AnimatedGraphicsModule::changeAnimation(EntityState state) {
    auto animation = animations.find(state);
    if(currentState != state && animation != animations.end()) {
        currentState = state;
        sprite.setAnimation(animation->second);
    }
}

void AnimatedGraphicsModule::move(int x, int y) {
    sprite.move(x, y);
}

void AnimatedGraphicsModule::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

void AnimatedGraphicsModule::setScale(float x, float y) {
    sprite.setScale(x, y);
}

sf::Vector2f AnimatedGraphicsModule::getPosition() const {
    return sprite.getPosition();
}

sf::FloatRect AnimatedGraphicsModule::getRect() const {
    return sprite.getGlobalBounds();
}

