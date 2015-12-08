#include "levelhandler.hpp"
#include <iostream>

LevelHandler::LevelHandler(const char* path) {
    lua.Load(path);
}

void LevelHandler::createLevel(Level &level) {
    level = Level();

    //Load textures
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(lua["backgroundSrc"]);
    textures.push_back(*texture);
    level.setBackground(*texture);

    auto luaEntities = lua["entities"];
    int entitiesSize = lua["entitiesSize"];
    for(int i = 1; i <= entitiesSize; i++) {
        auto entityParent = luaEntities[i];
        auto entity = entityParent[1];
        auto graphics = entity["graphics"];


        texture = new sf::Texture();
        texture->loadFromFile(graphics["spriteSheet"]);
        textures.push_back(*texture);

        auto stillRight = graphics["states"]["stillRight"]["frames"][1];
    //    sprite.setTextureRect(sf::IntRect(stillRight[1], stillRight[2], stillRight[3], stillRight[4]));
    //    sprite.setPosition((int)entityParent["x"], (int)entityParent["y"]);

        level.addEntity(*texture, sf::IntRect(stillRight[1], stillRight[2], stillRight[3], stillRight[4]));
    }
    texture = new sf::Texture();
}

