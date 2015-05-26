#include "level.hpp"

Level::Level(sf::Texture &backgroundTexture, sf::Texture &platformTexture) : Entity(backgroundTexture) {
    setPosition(0, 0);

    Entity platform(platformTexture);
    platform.setPosition(200, 450);
    platform.setScale(0.5, 0.5);
    platforms.push_back(platform);
}


void Level::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    Entity::draw(target, states);

    for(auto &platform : platforms) {
        target.draw(platform, states);
    }
}

std::vector<Entity>& Level::getPlatforms() {
    return platforms;
}
