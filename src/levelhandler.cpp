#include "levelhandler.hpp"
#include "modules/module.hpp"
#include "modules/animatedgraphicsmodule.hpp"
#include "modules/physicsmodule.hpp"
#include "modules/controlmodule.hpp"
#include <iostream>

LevelHandler::LevelHandler(const char* path) {
    lua.Load(path);
}

void LevelHandler::createLevel(Level &level) {
    level = Level();

    //Set background texture
    sf::Texture *texture = new sf::Texture();
    texture->loadFromFile(lua["backgroundSrc"]);
    textures.push_back(texture);
    level.setBackground(*texture);

    auto entityArray = lua["entities"];
    int entitiesSize = lua["entitiesSize"];
    for(int i = 1; i <= entitiesSize; i++) {
        auto entityParent = entityArray[i];
        auto entityObject = entityParent[1];

        //Start creation of entity
        Entity entity;

        //Graphical data
        auto graphics = entityObject["graphics"];
        bool isAnimated = graphics["isAnimated"];
        texture = new sf::Texture();
        texture->loadFromFile(graphics["spriteSheet"]);
        if(isAnimated) {
            AnimatedGraphicsModule *graphicsModule = new AnimatedGraphicsModule();

            auto states = graphics["states"];
            int statesSize = states["size"];
            for(int i = 1; i <= statesSize; i++) {
                Animation animation;
                animation.setSpriteSheet(*texture);

                //Get frame dimensions
                auto state = states[i];
                auto frames = state["frames"];
                int framesSize = frames["size"];
                for(int j = 1; j <= framesSize; j++) {
                    auto frame = frames[j];
                    animation.addFrame(sf::IntRect(frame[1], frame[2], frame[3], frame[4]));
                }

                //Get frame state
                int action = state["action"];
                int direction = state["direction"];
                EntityState entityState;
                entityState.setAction(static_cast<Action>(action));
                entityState.setDirection(static_cast<Direction>(direction));

                graphicsModule->addAnimation(entityState, animation);
            }
            int action = entityParent["action"];
            int direction = entityParent["direction"];
            EntityState entityState;
            entityState.setAction(static_cast<Action>(action));
            entityState.setDirection(static_cast<Direction>(direction));
            graphicsModule->changeAnimation(entityState);

            entity.addModule(GRAPHICS, graphicsModule);
            entity.setPosition((int)entityParent["x"], (int)entityParent["y"]);
        } else {
            //TODO: actually do something here
        }
        textures.push_back(texture);

        //Physics module
        auto physics = entityObject["physics"];
        bool canMove = physics["canMove"];
        bool canFall = physics["canFall"];
        int  mass = physics["mass"];
        int floorHeight = entityParent["floorHeight"];
        int gravity = entityParent["gravity"];


        PhysicsModule *physicsModule = new PhysicsModule();
        physicsModule->setMovable(canMove);
        physicsModule->setFall(canFall);
        physicsModule->setMass(mass);
        physicsModule->setFloorHeight(floorHeight);
        physicsModule->setGravity(gravity);
        entity.addModule(PHYSICS, physicsModule);

        //Control module
        auto control = entityObject["control"];
        bool userControlled = control["userControlled"];
        if(userControlled) {
            ControlModule *controlModule = new ControlModule();

            int up = control["up"];
            EntityState upState(UP, CLIMBING);
            sf::Keyboard::Key upKey = static_cast<sf::Keyboard::Key>(up);
            controlModule->addKey(upState, upKey);

            int down = control["down"];
            EntityState downState(DOWN, CLIMBING);
            sf::Keyboard::Key downKey = static_cast<sf::Keyboard::Key>(down);
            controlModule->addKey(downState, downKey);

            int left = control["left"];
            EntityState leftState(LEFT, WALKING);
            sf::Keyboard::Key leftKey = static_cast<sf::Keyboard::Key>(left);
            controlModule->addKey(leftState, leftKey);

            int right = control["right"];
            EntityState rightState(RIGHT, WALKING);
            sf::Keyboard::Key rightKey = static_cast<sf::Keyboard::Key>(right);
            controlModule->addKey(rightState, rightKey);

            std::cout << upState.getDirection() << "\t" << downState.getDirection() << "\t" << leftState.getDirection() << "\t" << rightState.getDirection() << std::endl;

            entity.addModule(CONTROL, controlModule);
        }

        level.addEntity(entity);
    }
    texture = nullptr;
}

