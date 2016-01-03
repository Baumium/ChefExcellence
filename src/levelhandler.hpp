#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP

#include "../lib/selene/include/selene.h"
#include "level.hpp"
#include <SFML/Graphics.hpp>

class LevelHandler {
    private:
        sel::State lua{true};
        std::vector<sf::Texture*> textures;

    public:
        LevelHandler(const char* path);
        void createLevel(Level &level);
};

#endif
