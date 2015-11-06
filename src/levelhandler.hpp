#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP

#include "level.hpp"
#include "../lib/selene/include/selene.h"

class LevelHandler {
    private:
        //sel::State lua;

    public:
        LevelHandler(const char* path);
        void createLevels(std::vector<Level> &levels);
};


#endif
