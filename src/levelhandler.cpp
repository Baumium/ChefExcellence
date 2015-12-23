#include "levelhandler.hpp"
#include "animatedentity.hpp"
#include "staticentity.hpp"
#include "animatedentity.hpp"
#include <iostream>

LevelHandler::LevelHandler(const char* path) {
    lua.Load(path);
}

void LevelHandler::createLevel(Level &level) {
    level = Level();

    //Set background texture
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(lua["backgroundSrc"]);
    textures.push_back(*texture);
    level.setBackground(*texture);

    auto entityArray = lua["entities"];
    int entitiesSize = lua["entitiesSize"];
    for(int i = 1; i <= entitiesSize; i++) {
        auto entityParent = entityArray[i];
        auto entityObject = entityParent[1];

        //Start creation of entity
        Entity *entity;

        //Graphical data
        auto graphics = entityObject["graphics"];
        bool isAnimated = graphics["isAnimated"];
        texture = new sf::Texture();
        texture->loadFromFile(graphics["spriteSheet"]);
        if(isAnimated) {
            std::map<Direction, Animation> animations;

            auto states = graphics["states"];
            int statesSize = states["size"];
            for(int i = 1; i <= statesSize; i++) {
                Animation animation;
                animation.setSpriteSheet(*texture);

                auto state = states[i];
                auto frames = state["frames"];
                int framesSize = frames["size"];
                int stateType = state["stateType"];
                for(int j = 1; j <= framesSize; j++) {
                    auto frame = frames[j];
                    animation.addFrame(sf::IntRect(frame[1], frame[2], frame[3], frame[4]));
                }

                animations.insert(std::pair<Direction, Animation>(static_cast<Direction>(stateType), animation));
            }
            std::cout << animations.size() << std::endl;

            entity = new AnimatedEntity(animations);
            entity->setPosition((int)entityParent["x"], (int)entityParent["y"]);
        } else {
            //TODO: actually do something here
            entity = new StaticEntity(*texture, sf::IntRect(0, 0, 0, 0));
        }

        textures.push_back(*texture);

        level.addEntity(entity);
    }
    texture = nullptr;
}

