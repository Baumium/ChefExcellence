#ifndef LEVELHANDLER_HPP
#define LEVELHANDLER_HPP

#include "level.hpp"
#include "pugixml.hpp"

class LevelHandler {
    private:
        pugi::xml_document file;
        bool isLoaded;
    public:
        LevelHandler(const char* path);
        void createLevels(std::vector<Level> &levels);
};


#endif
