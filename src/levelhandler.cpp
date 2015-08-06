#include "levelhandler.hpp"
#include <iostream>
#include <string>

LevelHandler::LevelHandler(const char* path) {
    if(file.load_file(path)) {
        isLoaded = true;
    } else {
        isLoaded = false;
    }
}

void LevelHandler::createLevels(std::vector<Level> &levels) {
    std::string platformName = "platform";
    if(isLoaded) {
        std::cout << "Creating levels..." << std::endl;
        for(pugi::xml_node level = file.child("levels").first_child(); level; level = level.next_sibling()) {
            //Get first level item - background
            pugi::xml_node node = level.child("background");

            //Background
            //TODO: create background via data

            //Create all entities
            node = level.child("entities");
            if(node) {
                for(pugi::xml_node entity = node.first_child(); entity; entity = entity.next_sibling()) {
                    std::cout << entity.name() << std::endl;
                    for(pugi::xml_attribute attribute = entity.first_attribute(); attribute; attribute = attribute.next_attribute()) {

                    }
                    //TODO: create levels based on xml values
                }
            }
        }
    } else {
        std::cout << "Level data not loaded!" << std::endl;
    }
}
